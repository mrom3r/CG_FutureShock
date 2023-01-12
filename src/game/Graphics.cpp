
#include "Graphics.hpp"

GLFWwindow *window;

Graphics::Graphics() {
    //Initialize window
    bool windowInitialized = initializeWindow();
    if (!windowInitialized) {
        throw std::runtime_error("can't initialize Window");
    }

    //Initialize vertex buffer
    initializeVertexBuffer();

    // Create and compile our GLSL program from the shaders
    program_ID = LoadShaders(R"(..\game\shader\VertexShader.vertexshader)",
                             R"(..\game\shader\FragmentShader.fragmentshader)");

    window_pointer = std::make_shared<GLFWwindow *>(window);
}

Graphics::~Graphics() {
    //Cleanup and close window
    cleanupVertexBuffer();
    glDeleteProgram(program_ID);
    closeWindow();
}

bool Graphics::initializeWindow() {
    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // only for macOS
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(1440, 810, "FutureShock", nullptr, nullptr);
    if (window == nullptr) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible."
                        " Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return false;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    return true;
}

void Graphics::framebuffer_size_callback(GLFWwindow *, int width, int height) {
    // keep display dimension 16:9
    int game_width;
    int game_height;
    int half_gap_x{};
    int half_gap_y{};
    if (width > height) {
        // width larger
        game_width = {static_cast<int>(static_cast<float>(height) * (16.0f / 9.0f))};
        game_height = {height};
        half_gap_x = {(width - game_width) / 2};
    } else {
        // height larger
        game_width = {width};
        game_height = {static_cast<int>(static_cast<float>(width) * (9.0f / 16.0f))};
        half_gap_y = {(height - game_height) / 2};
    }

    glViewport(half_gap_x, half_gap_y, game_width, game_height);
}

void Graphics::initializeVertexBuffer() {
    glGenVertexArrays(1, &vertex_array_object);
    glGenBuffers(1, &vertex_buffer_object);

    glBindVertexArray(vertex_array_object);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
}

bool Graphics::cleanupVertexBuffer() {
    glDeleteBuffers(1, &vertex_buffer_object);
    glDeleteVertexArrays(1, &vertex_array_object);
    return true;
}

bool Graphics::closeWindow() {
    glfwTerminate();
    return true;
}

void Graphics::drawGameObject(const GameObject &game_object) const {
    // define color
    int vertexColorLocation = glGetUniformLocation(program_ID, "myColor");
    glUniform4f(vertexColorLocation, game_object.color.red, game_object.color.green, game_object.color.blue,
                game_object.color.alpha);

    // Use shader
    glUseProgram(program_ID);

    float rotation_rad = game_object.rotation / 180.0f * 3.14159265358979323846f;
    glm::mat2 rotation_matrix{std::cos(rotation_rad), -std::sin(rotation_rad),
                              std::sin(rotation_rad), std::cos(rotation_rad)};

    glm::vec2 rotation{game_object.rotation_point.x, game_object.rotation_point.y};
    glm::vec2 translation{game_object.translation.x, game_object.translation.y};

    std::vector<glm::vec2> tmp_points{};

    for (Position position: game_object.positions) {
        glm::vec2 tmp_point{glm::vec2{position.x, position.y}};
        tmp_point -= rotation;
        tmp_point = rotation_matrix * tmp_point + translation;
        tmp_point += rotation;
        tmp_points.emplace_back(tmp_point);
    }

    std::vector<GLfloat> vertices{};

    for (glm::vec2 vector: tmp_points) {
        vertices.emplace_back(vector.x);
        vertices.emplace_back(vector.y);
    }

    glEnableVertexAttribArray(0);

    glBufferData(GL_ARRAY_BUFFER, sizeof(std::vector<GLfloat>) + (sizeof(GLfloat) * vertices.size()), vertices.data(),
                 GL_STATIC_DRAW);
    glVertexAttribPointer(
            0,          // attribute 0. No particular reason for 0, but must match the layout in the shader.
            2,          // number of components per generic vertex attribute. Must be 1, 2, 3, 4.
            GL_FLOAT,   // type
            GL_FALSE,   // normalized
            0,          // stride
            nullptr     // array buffer offset
    );

    // Draw
    glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLint>(tmp_points.size()));

    glDisableVertexAttribArray(0);
}

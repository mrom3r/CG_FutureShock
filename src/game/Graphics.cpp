
#include "Graphics.hpp"
#include "GameObject.hpp"

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
    program_ID = LoadShaders(R"(..\src\game\shader\VertexShader.vertexshader)",
                             R"(..\src\game\shader\FragmentShader.fragmentshader)");

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

void
Graphics::drawTriangle(Position first, Position second, Position third, float rotation, Position rotation_point) const {
    // Use shader
    glUseProgram(program_ID);

    GLfloat vertices[]{
            first.x, first.y, 0.0f,
            second.x, second.y, 0.0f,
            third.x, third.y, 0.0f
    };

    if (rotation != 0) {
        float rotation_rad = rotation / 180.0f * 3.14159265358979323846f;
        glm::mat2 myR = glm::mat2(std::cos(rotation_rad), -std::sin(rotation_rad),
                                  std::sin(rotation_rad), std::cos(rotation_rad));

        glm::vec2 rotation_point_tmp = glm::vec2(rotation_point.x, rotation_point.y);

        glm::vec2 rotated_first = glm::vec2(first.x, first.y) - rotation_point_tmp;
        glm::vec2 rotated_second = glm::vec2(second.x, second.y) - rotation_point_tmp;
        glm::vec2 rotated_third = glm::vec2(third.x, third.y) - rotation_point_tmp;

        rotated_first = myR * rotated_first;
        rotated_second = myR * rotated_second;
        rotated_third = myR * rotated_third;

        rotated_first += rotation_point_tmp;
        rotated_second += rotation_point_tmp;
        rotated_third += rotation_point_tmp;

        vertices[0] = rotated_first[0];
        vertices[1] = rotated_first[1];
        vertices[2] = 0.0f;
        vertices[3] = rotated_second[0];
        vertices[4] = rotated_second[1];
        vertices[5] = 0.0f;
        vertices[6] = rotated_third[0];
        vertices[7] = rotated_third[1];
        vertices[8] = 0.0f;
    }

    glEnableVertexAttribArray(0);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized
            0,                  // stride
            (void *) nullptr    // array buffer offset
    );

    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
}

void Graphics::drawRectangle(Position position, float width, float height) const {
    // TODO find better solution
    Position first{position.x, position.y};
    Position second{position.x + width, position.y};
    Position third{position.x + width, position.y + height};
    Position fourth{position.x, position.y + height};
    drawTriangle(first, second, third, 0, Position());
    drawTriangle(first, third, fourth, 0, Position());
}

void Graphics::drawGameObject(const GameObject& game_object) const {
    // Use shader
    glUseProgram(program_ID);

    float rotation_rad = game_object.rotation / 180.0f * 3.14159265358979323846f;
    glm::mat2 myR = glm::mat2(std::cos(rotation_rad), -std::sin(rotation_rad),
                              std::sin(rotation_rad), std::cos(rotation_rad));

    glm::vec2 rotation_point_tmp = glm::vec2(game_object.rotation_point.x, game_object.rotation_point.y);

    std::vector<glm::vec2> rotated_points{};

    for (Position position: game_object.shape.positions) {
        glm::vec2 tmp_point{glm::vec2{position.x, position.y} - rotation_point_tmp};
        tmp_point *= tmp_point;
        tmp_point += rotation_point_tmp;
        rotated_points.emplace_back(tmp_point);
    }

    std::vector<GLfloat> vertices{};

    for (glm::vec2 vector : rotated_points) {
        vertices.emplace_back(vector.x);
        vertices.emplace_back(vector.y);
        vertices.emplace_back(0.0);
    }

    glEnableVertexAttribArray(0);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,    // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized
            0,                  // stride
            (void *) nullptr    // array buffer offset
    );

    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
}

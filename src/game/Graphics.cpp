
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
    program_ID = LoadShaders(R"(..\src\game\shader\VertexShader.vertexshader)",
                             R"(..\src\game\shader\FragmentShader.fragmentshader)");

    //start animation loop until escape key is pressed
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        drawEnvironment();
        //drawTriangle({-1.0, -1.0}, {0.0, 0.0}, {-1.0, 0.0});
        //drawTriangle({0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0});
        drawRectangle({-0.5, -0.5}, 1.0, 1.0);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
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

void Graphics::drawEnvironment() {
}

void Graphics::drawTriangle(Position first, Position second, Position third) const {
    // Use shader
    glUseProgram(program_ID);

    GLfloat vertices[]{
            first.x, first.y, 0.0f,
            second.x, second.y, 0.0f,
            third.x, third.y, 0.0f
    };

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
}

void Graphics::drawRectangle(Position position, float width, float height) const {
    // Use shader
    glUseProgram(program_ID);

    GLfloat vertices[] {
            0.0f, 0.0f, 0.0f,
            0.0f, 0.5f, 0.0f,
            0.5f, 0.5f, 0.0f,
            0.5f, 0.0f, 0.0f
    };

    glEnableVertexAttribArray(0);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            4,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized
            0,                  // stride
            (void *) nullptr    // array buffer offset
    );

    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 4);
}

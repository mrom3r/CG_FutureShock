#include "mainLoop.hpp"

// Include standard headers
#include <cstdio>

// Include GLFW
#include <glfw3.h>

GLFWwindow *window;

// Include GLM
#include <glm/glm.hpp>

using namespace glm;

#include <common/shader.hpp>
#include <iostream>

glm::vec2 triangleVertex1{-0.5f, -0.5f};
glm::vec2 triangleVertex2{0.5f, -0.5f};
glm::vec2 triangleVertex3{0.0f, 0.5f};

glm::mat2 myR{1.0f, 0.0f,
              0.0f, 1.0f};
glm::vec2 myT{0.2f, 0.2f};

int main() {
    //Initialize window
    bool windowInitialized = initializeWindow();
    if (!windowInitialized) return -1;

    //Initialize vertex buffer
    bool vertexBufferInitialized = initializeVertexBuffer();
    if (!vertexBufferInitialized) return -1;

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders(R"(..\src\game\shader\VertexShader.vertexshader)",
                            R"(..\src\game\shader\FragmentShader.fragmentshader)");

    //start animation loop until escape key is pressed
    do {
        myR += glm::mat2 {0.01f, 0.0f,0.0f, 0.01f};
        //myT += glm::vec2{0.001f, 0.01f};

        triangleVertex1 = myR * triangleVertex1 + myT;
        triangleVertex2 = myR * triangleVertex2 + myT;
        triangleVertex3 = myR * triangleVertex3 + myT;

        updateAnimationLoop();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    //Cleanup and close window
    cleanupVertexBuffer();
    glDeleteProgram(programID);
    closeWindow();

    return 0;
}

void updateAnimationLoop() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) nullptr    // array buffer offset
    );

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, vertexBuffer_size); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();

    initializeVertexBuffer();
}

bool initializeWindow() {
    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(1024, 768, "Tutorial 02 - Red triangle", nullptr, nullptr);
    if (window == nullptr) {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

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

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    return true;
}

bool initializeVertexBuffer() {
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    vertexBuffer_size = 3;

    triangleVertex1 = myR * triangleVertex1 + myT;
    triangleVertex2 = myR * triangleVertex2 + myT;
    triangleVertex3 = myR * triangleVertex3 + myT;

    static GLfloat g_vertex_buffer_data[]{
            triangleVertex1[0], triangleVertex1[1], 0.0f,
            triangleVertex2[0], triangleVertex2[1], 0.0f,
            triangleVertex3[0], triangleVertex3[1], 0.0f,
    };

    g_vertex_buffer_data[0] = triangleVertex1[0];
    g_vertex_buffer_data[1] = triangleVertex1[1];
    g_vertex_buffer_data[2] = triangleVertex2[0];
    g_vertex_buffer_data[3] = triangleVertex2[1];
    g_vertex_buffer_data[4] = triangleVertex3[0];
    g_vertex_buffer_data[5] = triangleVertex3[1];

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    return true;
}

bool cleanupVertexBuffer() {
    // Cleanup VBO
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteVertexArrays(1, &VertexArrayID);
    return true;
}

bool closeWindow() {
    glfwTerminate();
    return true;
}

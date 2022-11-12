#ifndef PLAYGROUND_H
#define PLAYGROUND_H

// Include GLEW
#include <GL/glew.h>
#include <glm/detail/type_mat.hpp>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat2x2.hpp>
#include <vector>

class Graphics {

    GLfloat vertex_buffer_data[9] {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };

    GLuint vertex_buffer_size{};
    GLuint vertex_buffer_object{};
    GLuint vertex_array_object{};

    // program ID of the shaders, required for handling the shaders with OpenGL
    GLuint program_ID{};

    void drawGame();

    // initializes the window using GLFW and GLEW
    bool initializeWindow();

    // initializes the vertex buffer array and binds it OpenGL
    void initializeVertexBuffer();

    // frees all resources from the vertex buffer
    bool cleanupVertexBuffer();

    // closes the OpenGL window and terminates GLFW
    bool closeWindow();

public:
    Graphics();
    ~Graphics();
};

#endif

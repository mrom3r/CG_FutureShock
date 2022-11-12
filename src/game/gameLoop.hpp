#ifndef PLAYGROUND_H
#define PLAYGROUND_H

// Include GLEW
#include <GL/glew.h>
#include <glm/detail/type_mat.hpp>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat2x2.hpp>
#include <vector>

static const GLfloat vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
};

GLuint vertex_buffer_size{};
GLuint vertex_buffer_object{};
GLuint vertex_array_object{};

// program ID of the shaders, required for handling the shaders with OpenGL
GLuint program_ID{};

int main(); //<<< main function, called at startup
void drawGame(); //<<< updates the animation loop
bool initializeWindow(); //<<< initializes the window using GLFW and GLEW
bool initializeVertexBuffer(); //<<< initializes the vertex buffer array and binds it OpenGL
bool cleanupVertexBuffer(); //<<< frees all recources from the vertex buffer
bool closeWindow(); //<<< Closes the OpenGL window and terminates GLFW

#endif

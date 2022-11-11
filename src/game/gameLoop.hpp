#ifndef PLAYGROUND_H
#define PLAYGROUND_H

// Include GLEW
#include <GL/glew.h>
#include <glm/detail/type_mat.hpp>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat2x2.hpp>

//some global variables for handling the vertex buffer
GLuint vertexBuffer;
GLuint VertexArrayID;
GLint vertexBuffer_size;

//program ID of the shaders, required for handling the shaders with OpenGL
GLuint programID;

int main(); //<<< main function, called at startup
void updateAnimationLoop(); //<<< updates the animation loop
bool initializeWindow(); //<<< initializes the window using GLFW and GLEW
bool initializeVertexBuffer(); //<<< initializes the vertex buffer array and binds it OpenGL
bool cleanupVertexBuffer(); //<<< frees all recources from the vertex buffer
bool closeWindow(); //<<< Closes the OpenGL window and terminates GLFW

#endif

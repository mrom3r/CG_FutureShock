
#ifndef PLAYGROUND_H
#define PLAYGROUND_H

// Include GLEW
#include <GL/glew.h>
#include <glm/detail/type_mat.hpp>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat2x2.hpp>
#include <vector>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>

// Include standard headers
#include <cstdio>
#include <common/shader.hpp>
#include <iostream>
#include <memory>
#include <cmath>

#include "Position.hpp"
#include "GameObject.hpp"

class Graphics {

    GLuint vertex_buffer_size{};

    GLuint vertex_buffer_object{};
    GLuint vertex_array_object{};

    // program ID of the shaders, required for handling the shaders with OpenGL
    GLuint program_ID{};

    // initializes the window using GLFW and GLEW
    static bool initializeWindow();

    // whenever the _window size changed (by OS or user resize) this callback function executes
    static void framebuffer_size_callback(GLFWwindow *_window, int width, int height);

    // initializes the vertex buffer array and binds it OpenGL
    void initializeVertexBuffer();

    // frees all resources from the vertex buffer
    bool cleanupVertexBuffer();

    // closes the OpenGL window and terminates GLFW
    static bool closeWindow();

public:

    std::shared_ptr<GLFWwindow *> window_pointer{};

    void drawTriangle(Position first, Position second, Position third, float rotation, Position rotation_point) const;

    void drawRectangle(Position position, float width, float height) const;

    void drawGameObject(const GameObject &game_object) const;

    Graphics();

    ~Graphics();
};

#endif

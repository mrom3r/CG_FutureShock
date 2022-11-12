
#include "Graphics.hpp"

int main() {
    Graphics graphics{};

    //start animation loop until escape key is pressed
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        graphics.drawRectangle({0.0, 0.0}, 1.0, 1.0);

        // Swap buffers
        glfwSwapBuffers(*graphics.window_pointer);
        glfwPollEvents();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(*graphics.window_pointer, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(*graphics.window_pointer) == 0);
}


#include "Graphics.hpp"

int main() {
    Graphics graphics{};

    GLFWwindow *local_window{*graphics.window_pointer};

    //start animation loop until escape key is pressed
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //graphics.drawRectangle({0.0, 0.0}, 1.0, 1.0);
        static float test = -5;
        graphics.drawTriangle({-0.8, -0.8}, {0.0, -0.8}, {0.0, 0.0}, test, {-0.4, -0.4});
        test += 0.1;

        // Swap buffers
        glfwSwapBuffers(local_window);
        glfwPollEvents();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(local_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(local_window) == 0);
}

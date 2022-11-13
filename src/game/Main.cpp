
#include <chrono>
#include <thread>

#include "Graphics.hpp"
#include "Game.hpp"

int main() {
    Graphics graphics{};
    Game game{graphics};

    GLFWwindow *local_window{*graphics.window_pointer};

    static const std::chrono::milliseconds frame_millis{10};
    auto end_time = std::chrono::steady_clock::now();

    //start animation loop until escape key is pressed
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto start_time = std::chrono::steady_clock::now();
        auto elapsed_time{start_time - end_time};

        // don't run faster than frame_millis per frame
        if (elapsed_time < frame_millis) {
            std::this_thread::sleep_for(frame_millis - elapsed_time);
        }

        end_time = start_time;

        game.update_game(elapsed_time);
        game.draw_game();

        // Swap buffers
        glfwSwapBuffers(local_window);
        glfwPollEvents();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(local_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(local_window) == 0);
}

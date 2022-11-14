
#include <chrono>
#include <thread>

#include "Graphics.hpp"
#include "Game.hpp"

int main() {
    Graphics graphics{};
    Game game{graphics};

    GLFWwindow *local_window{*graphics.window_pointer};

    glClearColor(0.0, 0.0, 0.3, 1.0);

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

        // handle player input
        if (glfwGetKey(local_window, GLFW_KEY_W) == GLFW_PRESS) {
            game.player.lift_canon();
        }
        if (glfwGetKey(local_window, GLFW_KEY_A) == GLFW_PRESS) {
            game.player.translation += Position{-0.001, 0.0};
        }
        if (glfwGetKey(local_window, GLFW_KEY_S) == GLFW_PRESS) {
            game.player.lower_canon();
        }
        if (glfwGetKey(local_window, GLFW_KEY_D) == GLFW_PRESS) {
            game.player.translation += Position{0.001, 0.0};
        }
        if (glfwGetKey(local_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            game.player.shoot_canon();
        }

        if (glfwGetKey(local_window, GLFW_KEY_UP) == GLFW_PRESS) {
            game.enemy.lift_canon();
        }
        if (glfwGetKey(local_window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            game.enemy.translation += Position{-0.001, 0.0};
        }
        if (glfwGetKey(local_window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            game.enemy.lower_canon();
        }
        if (glfwGetKey(local_window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            game.enemy.translation += Position{0.001, 0.0};
        }
        if (glfwGetKey(local_window, GLFW_KEY_ENTER) == GLFW_PRESS) {
            game.enemy.shoot_canon();
        }

        game.update_game(elapsed_time);
        game.draw_game();

        // Swap buffers
        glfwSwapBuffers(local_window);
        glfwPollEvents();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(local_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(local_window) == 0);
}


#include "Game.hpp"

Game::Game(const Graphics& _graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};
    update_positions();
}

void Game::update_positions() {

}

void Game::draw_game() {
    draw_background();
    draw_bullets();
    draw_player();
}

void Game::draw_background() {
    static float test = -5;
    graphics->drawTriangle({-0.8, -0.8}, {0.0, -0.8}, {0.0, 0.0}, test, {-0.4, -0.4});
    test += 0.1;
}

void Game::draw_bullets() {

}

void Game::draw_player() {

}
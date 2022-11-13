
#include "Game.hpp"

Game::Game(const Graphics& _graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};
    update_positions();
    draw_game();
}

void Game::update_positions() {

}

void Game::draw_game() {
    draw_background();
    draw_bullets();
    draw_player();
}

void Game::draw_background() {

}

void Game::draw_bullets() {

}

void Game::draw_player() {

}
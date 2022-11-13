
#include "Game.hpp"

Game::Game(const Graphics &_graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {
    game_objects.clear();

    //background
    game_objects.emplace_back(GameObject{
            {{0.0, -0.6}, {-1.0, -0.4}, {-1.0, -1.0}, {1.0, -1.0}, {1.0, -0.3}}}
    );

    // player
    GameObject player{rectangle_positions({}, 0.1, 0.05)};
    player.translation.x = 0.0005f;
    player.translation.y = 0.0005f;
    player.rotation = 15;
    game_objects.push_back(player);
}

void Game::draw_game() {
    for (const GameObject &game_object: game_objects) {
        graphics->drawGameObject(game_object);
    }
}

std::vector<Position> Game::rectangle_positions(Position position, float width, float height) {
    return {{position.x, position.y},
            {position.x + width, position.y},
            {position.x + width, position.y + height},
            {position.x, position.y + height}};
}

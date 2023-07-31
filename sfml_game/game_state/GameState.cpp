#include "GameState.hpp"

GameState::GameState(sf::RenderWindow *window)
    : State(window)
{
}

GameState::~GameState()
{
}

void GameState::end_state()
{
}

void GameState::update(const float &date_time)
{
    std::cout << "Hello, from GameState!\n";
}

void GameState::render(sf::RenderTarget *target)
{
}

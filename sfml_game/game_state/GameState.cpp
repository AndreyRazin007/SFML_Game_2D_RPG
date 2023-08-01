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
    std::cout << "Ending GameState!\n";
}

void GameState::update_keybinds(const float &date_time)
{
    this->check_for_quit();
}

void GameState::update(const float &date_time)
{
    this->update_keybinds(date_time);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "Pressed A\n";
    }
}

void GameState::render(sf::RenderTarget *target)
{
}

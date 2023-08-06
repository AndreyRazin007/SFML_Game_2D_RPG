#include "GameState.hpp"

#include <iostream>

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

    this->m_player.update(date_time);
}

void GameState::render(sf::RenderTarget *target)
{
	if (target)
	{

	}
	else
	{
		this->m_player.render(this->m_window);
	}
}

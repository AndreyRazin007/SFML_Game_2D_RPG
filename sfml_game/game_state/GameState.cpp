#include "GameState.hpp"

#include <iostream>
#include <fstream>

GameState::GameState(sf::RenderWindow *window,
	std::map<std::string, int64_t> *supported_keys)
    : State(window, supported_keys)
{
	init_key_binds();
}

/* Initialization of keys in the game. */
void GameState::init_key_binds()
{
	std::ifstream ifsream{"Config/game_state_key_binds.ini"};

	if (ifsream.is_open())
	{
		std::string key_1{""};
		std::string key_2{""};

		while (ifsream >> key_1 >> key_2)
		{
			m_key_binds[key_1] = m_supported_keys->at(key_2);
		}
	}

	ifsream.close();
}

/* Drawing the game state. */
void GameState::render(sf::RenderTarget *target)
{
	if (!target)
	{
		target = m_window;
	}

	m_player.render(target);
}

/* Processing of key presses in the game. */
void GameState::update_input(const float &date_time)
{
	using keyboard_t = sf::Keyboard;
	using key_t = sf::Keyboard::Key;

	check_for_quit();

	/* Update player input. */
	if (keyboard_t::isKeyPressed(key_t(m_key_binds.at("move_left"))))
	{
		m_player.move(date_time, -1.0f, 0.0f);
	}
	else if (keyboard_t::isKeyPressed(key_t(m_key_binds.at("move_right"))))
	{
		m_player.move(date_time, 1.0f, 0.0f);
	}

	if (keyboard_t::isKeyPressed(key_t(m_key_binds.at("move_up"))))
	{
		m_player.move(date_time, 0.0f, -1.0f);
	}
	else if (keyboard_t::isKeyPressed(key_t(m_key_binds.at("move_down"))))
	{
		m_player.move(date_time, 0.0f, 1.0f);
	}
}

/* Updating game state. */
void GameState::update(const float &date_time)
{
	update_input(date_time);
	m_player.update(date_time);
}

void GameState::end_state()
{
    std::cout << "Ending GameState!\n";
}

GameState::~GameState()
{
}

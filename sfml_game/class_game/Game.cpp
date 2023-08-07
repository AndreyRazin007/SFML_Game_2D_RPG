#include "Game.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

Game::Game()
{
	init_window();
	init_keys();
	init_states();
}

/* Initialization window. */
void Game::init_window()
{
	/* Creates a SFML window using options from a window.ini file. */
	std::ifstream ifstream{"config/window.ini"};

	std::string title{"Window"};
	sf::VideoMode window_bounds{1000, 700};
	int64_t framerate_limit{ 120 };
	bool vertical_sync_enabled{ false };

	/* Reading from the window.ini file. */
	if (ifstream.is_open())
	{
		std::getline(ifstream, title);
		
		ifstream >> window_bounds.width >> window_bounds.height;
		ifstream >> framerate_limit;
		ifstream >> vertical_sync_enabled;
	}

	ifstream.close();

	/* Create window. */
	m_window = { new sf::RenderWindow{ window_bounds, title } };
	
	/* Limit of fps. */
	m_window->setFramerateLimit(framerate_limit);

	/* Vertical sync. */
	m_window->setVerticalSyncEnabled(vertical_sync_enabled);
}

/* Key processing. */
void Game::init_keys()
{
	std::ifstream ifsream{"Config/supported_keys.ini"};

	if (ifsream.is_open())
	{
		std::string key{""};
		int64_t key_value{ 0 };

		while (ifsream >> key >> key_value)
		{
			m_supported_keys[key] = key_value;
		}
	}

	ifsream.close();

	/* Debug, remove later. */
	for (const auto &element : m_supported_keys)
	{
		std::cout << element.first << ' ' << element.second << '\n';
	}
}

/* Status processing. */
void Game::init_states()
{
	m_states.push(new GameState(m_window, &m_supported_keys));
}

/* Drawing the application. */
void Game::render()
{
	/* Clearing each previous frame. */
	m_window->clear();

	if (not this->m_states.empty())
	{
		m_states.top()->render();
	}

	/* Render items. */
	m_window->display();
}

/* Starting the application. */
void Game::run()
{
	while (m_window->isOpen())
	{
		update_date_time();
		update();
		render();
	}
}

/* Updating SFML events for application. */
void Game::update_sfml_event()
{
	while (m_window->pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
		{
			m_window->close();
		}
	}
}

/* Update date and time for application. */
void Game::update_date_time()
{
	/* Updates the date_time variable with the time it takes to update
	       and render one frame. */
	m_date_time = m_date_time_clock.restart().asSeconds();
}

/* Updating application. */
void Game::update()
{
	update_sfml_event();

	if (not m_states.empty())
	{
		m_states.top()->update(m_date_time);

		if (m_states.top()->get_quit())
		{
			m_states.top()->end_state();
			delete m_states.top();
			m_states.pop();
		}
	}
	/* Application ending. */
	else
	{
		end_application();
		m_window->close();
	}
}

/* Regular functions. */
void Game::end_application()
{
	std::cout << "Ending Application!\n";
}

Game::~Game()
{
	delete m_window;

	while (not m_states.empty())
	{
		delete m_states.top();
		m_states.pop();
	}
}

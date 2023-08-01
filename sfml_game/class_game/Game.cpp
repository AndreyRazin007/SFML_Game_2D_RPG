#include "Game.hpp"

/* Initialization functions. */
void Game::init_window()
{
	/* Creates a SFML window using options from a window.ini file. */
	std::ifstream ifstream{"config/window.ini"}; // File config/window.ini

	std::string title{"Window"}; // Title window
	sf::VideoMode window_bounds{1000, 700}; // Size window
	unsigned int framerate_limit{ 120 }; // Framerate application
	bool vertical_sync_enabled{ false }; // Vertical sync

	/* Reading from the window.ini file. */
	if (ifstream.is_open())
	{
		std::getline(ifstream, title);
		
		ifstream >> window_bounds.width >> window_bounds.height;
		ifstream >> framerate_limit;
		ifstream >> vertical_sync_enabled;
	}

	ifstream.close(); // Close thread of file

	/* Create window */
	this->m_window = { new sf::RenderWindow{ window_bounds, title } };
	
	/* Limit of fps */
	this->m_window->setFramerateLimit(framerate_limit);

	/* Vertical sync */
	this->m_window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::init_states()
{
	this->m_states.push(new GameState(this->m_window));
}

Game::Game()
{
	this->init_window();
	this->init_states();
}

Game::~Game()
{
	delete this->m_window;

	while (not this->m_states.empty())
	{
		delete this->m_states.top();
		this->m_states.pop();
	}
}

/* Functions for SFML. */
void Game::end_application()
{
	std::cout << "Ending Application!\n";
}

void Game::run()
{
	while (this->m_window->isOpen())
	{
		this->update_date_time();
		this->update();
		this->render();
	}
}

void Game::render()
{
	/* Clearing each previous frame. */
	this->m_window->clear();

	if (not this->m_states.empty())
	{
		this->m_states.top()->render();
	}

	/* Render items. */
	this->m_window->display();
}

void Game::update_sfml_event()
{
	while (this->m_window->pollEvent(this->m_event))
	{
		if (this->m_event.type == sf::Event::Closed)
		{
			this->m_window->close();
		}
	}
}

void Game::update_date_time()
{
	/* Updates the date_time variable with the time it takes to update
	       and render one frame. */
	this->m_date_time = this->m_date_time_clock.restart().asSeconds();
}

void Game::update()
{
	this->update_sfml_event();

	if (not this->m_states.empty())
	{
		this->m_states.top()->update(this->m_date_time);

		if (this->m_states.top()->get_quit())
		{
			this->m_states.top()->end_state();
			delete this->m_states.top();
			this->m_states.pop();
		}
	}
	/* Application ending. */
	else
	{
		this->end_application();
		this->m_window->close();
	}
}

#ifndef GAME_HPP
#define GAME_HPP

#include "../game_state/GameState.hpp"

#include <stack>

class Game
{
private:
	/* Options. */
	sf::RenderWindow *m_window{};
	sf::Event m_event {};
	sf::Clock m_date_time_clock{};

	float m_date_time{};

	std::stack<State*> m_states{};

	/* Initialization functions. */
	void init_window();
	void init_states();

public:
	Game();
	virtual ~Game();

	/* Functions for SFML. */

	/* Regular functions. */
	void end_application();

	/* Starting the application. */
	void run();

	/* Drawing the application. */
	void render();

	/* Updating SFML events for application. */
	void update_sfml_event();

	/* Update date and time for application. */
	void update_date_time();

	/* Updating application. */
	void update();
};

#endif

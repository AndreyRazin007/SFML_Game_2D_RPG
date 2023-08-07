#ifndef GAME_HPP
#define GAME_HPP

#include "../game_state/GameState.hpp"

#include <stack>

class Game
{
private:
	sf::RenderWindow *m_window{};
	sf::Event m_event {};
	sf::Clock m_date_time_clock{};
	
	float m_date_time{};

	std::stack<State*> m_states{};
	std::map<std::string, int64_t> m_supported_keys{};

	/* Initialization functions. */

	/* Initialization window. */
	void init_window();
	
	/* Key processing. */
	void init_keys();
	
	/* Status processing. */
	void init_states();

public:
	Game();
	virtual ~Game();

	/* Functions for SFML. */

	/* Drawing the application. */
	void render();

	/* Starting the application. */
	void run();

	/* Updating SFML events for application. */
	void update_sfml_event();

	/* Update date and time for application. */
	void update_date_time();

	/* Updating application. */
	void update();

	/* Regular functions. */
	void end_application();
};

#endif

#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "../class_state/State.hpp"
#include "../class_entity/Entity.hpp"

class GameState : public State
{
private:
	Entity m_player{};

	/* Initialization of keys in the game. */
	void init_key_binds();

public:
	GameState(sf::RenderWindow *window,
		std::map<std::string, int64_t> *supported_keys);
	virtual ~GameState();

	/* Functions for SFML. */

	/* Drawing the game state. */
	void render(sf::RenderTarget *target = nullptr);
	
	/* Processing of key presses in the game. */
	void update_input(const float &date_time);
	
	/* Updating game state. */
	void update(const float &date_time);

	void end_state();
};

#endif

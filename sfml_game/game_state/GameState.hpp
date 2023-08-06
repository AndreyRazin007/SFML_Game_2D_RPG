#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "../class_state/State.hpp"
#include "../class_entity/Entity.hpp"

class GameState : public State
{
private:
	Entity m_player{};

public:
	GameState(sf::RenderWindow *window);
	virtual ~GameState();

	/* Functions for SFML. */
	void end_state();

	void update_keybinds(const float &date_time);
	void update(const float &date_time);
	void render(sf::RenderTarget *target = nullptr);
};

#endif

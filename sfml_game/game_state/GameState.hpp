#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "../class_state/State.hpp"

class GameState : public State
{
private:


public:
	GameState(sf::RenderWindow *window);

	virtual ~GameState();

	/* Functions for SFML. */
	void end_state();

	void update(const float &date_time);

	void render(sf::RenderTarget *target = nullptr);
};

#endif GAME_STATE_HPP

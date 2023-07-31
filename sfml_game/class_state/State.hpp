#ifndef STATE_HPP
#define STATE_HPP

#include "SFML/Graphics.hpp"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class State
{
private:
	/* Options. */
	sf::RenderWindow *m_window{};
	std::vector<sf::Texture> m_textures{};

public:
	State(sf::RenderWindow *window = nullptr);

	virtual ~State();

	virtual void end_state() = 0;

	virtual void update(const float &date_time) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;
};

#endif STATE_HPP

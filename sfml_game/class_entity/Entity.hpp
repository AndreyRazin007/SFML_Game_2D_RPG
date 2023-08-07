#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SFML/Graphics.hpp"

class Entity
{
private:
	sf::RectangleShape m_shape{};
	float m_movement_speed{};

public:
	Entity();
	virtual ~Entity();

	/* Functions. */

	/* Drawing the main character. */
	virtual void render(sf::RenderTarget *target);

	/* Main character movement. */
	virtual void move(const float &date_time, const float x, const float y);

	/* Main character update. */
	virtual void update(const float &date_time);
};

#endif

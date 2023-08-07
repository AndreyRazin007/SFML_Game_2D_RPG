#include "Entity.hpp"

Entity::Entity()
{
	m_shape.setSize(sf::Vector2f(100.0f, 100.0f));
	m_shape.setFillColor(sf::Color::Red);
	m_movement_speed = { 200.0f };
}

/* Drawing the main character. */
void Entity::render(sf::RenderTarget *target)
{
	target->draw(m_shape);
}

/* Main character movement. */
void Entity::move(const float &date_time, const float direction_x,
	const float direction_y)
{
	m_shape.move(direction_x * m_movement_speed * date_time,
		direction_y * m_movement_speed * date_time);
}

/* Main character update. */
void Entity::update(const float &date_time)
{
}

Entity::~Entity()
{
}

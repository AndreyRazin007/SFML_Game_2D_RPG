#include "Entity.hpp"

Entity::Entity()
{
	this->m_shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->m_shape.setFillColor(sf::Color::White);
	this->m_movement_speed = { 100.0f };
}

Entity::~Entity()
{
}

void Entity::render(sf::RenderTarget *target)
{
	target->draw(this->m_shape);
}

void Entity::move(const float &date_time, const float direction_x,
	const float direction_y)
{
	this->m_shape.move(direction_x * this->m_movement_speed * date_time,
		direction_y * this->m_movement_speed * date_time);
}

void Entity::update(const float &date_time)
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(date_time, -1.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(date_time, 1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(date_time, 0.0f, -1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(date_time, 0.0f, 1.0f);
	}
}

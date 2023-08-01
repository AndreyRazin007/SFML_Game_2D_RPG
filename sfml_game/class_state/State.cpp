#include "State.hpp"

State::State(sf::RenderWindow *window)
	: m_window{window}
{
	this->m_quit = { false };
}

State::~State()
{

}

void State::check_for_quit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->m_quit = { true };
	}
}

const bool &State::get_quit() const
{
	return this->m_quit;
}

#include "State.hpp"

State::State(sf::RenderWindow *window,
	std::map<std::string, int64_t> *supported_keys)
	: m_window{ window }, m_supported_keys{ supported_keys }, m_quit{ false }
{
}

/* Exit check. */
void State::check_for_quit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_key_binds.at("close"))))
	{
		m_quit = true;
	}
}

/* Return exit value. */
const bool &State::get_quit() const
{
	return m_quit;
}

State::~State()
{
}

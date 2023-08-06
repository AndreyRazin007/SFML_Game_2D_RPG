#ifndef STATE_HPP
#define STATE_HPP

#include "SFML/Graphics.hpp"

#include <vector>

class State
{
protected:
	/* Options. */
	sf::RenderWindow *m_window{};
	std::vector<sf::Texture> m_textures{};
	bool m_quit{};

public:
	State(sf::RenderWindow *window = nullptr);
	virtual ~State();

	const bool &get_quit() const;

	virtual void check_for_quit();

	virtual void end_state() = 0;
	virtual void update_keybinds(const float &date_time) = 0;
	virtual void update(const float &date_time) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;
};

#endif

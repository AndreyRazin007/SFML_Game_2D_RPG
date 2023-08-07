#ifndef STATE_HPP
#define STATE_HPP

#include "SFML/Graphics.hpp"

class State
{
protected:
	sf::RenderWindow *m_window{};
	std::map<std::string, int64_t> *m_supported_keys{};
	std::map<std::string, int64_t> m_key_binds{};
	bool m_quit{};

	/* Resources. */
	std::vector<sf::Texture> m_textures{};

	/* Functions. */
	virtual void init_key_binds() = 0;

public:
	State(sf::RenderWindow *window,
		std::map<std::string, int64_t> *supported_keys);
	virtual ~State();

	/* Exit check. */
	virtual void check_for_quit();

	/* Return exit value. */
	const bool &get_quit() const;

	virtual void render(sf::RenderTarget *target = nullptr) = 0;
	virtual void update_input(const float &date_time) = 0;
	virtual void update(const float &date_time) = 0;
	virtual void end_state() = 0;
};

#endif

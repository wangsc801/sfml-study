#ifndef GAME_HPP_
#define GAME_HPP_

#include "Window.hpp"
#include "World.hpp"

class Game{
public:
	Game();
	~Game();

	sf::Time GetElapsed();
	void RestartClock();
	Window* GetWindow();

	void Update();
	void Render();

private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;

	World m_world;
};

#endif

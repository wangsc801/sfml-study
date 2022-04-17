#ifndef GAME_HPP_
#define GAME_HPP_

#include "Window.hpp"

class Game
{
public:
	Game();
	~Game();
	void Update();
	void Render();
	Window *GetWindow();
	sf::Time GetElapsed();
	void RestartClock();

private:
	Window window;
	sf::Sprite dogSprite;
	sf::Texture dogTexture;
	sf::Vector2f dogMoveSpeed;
	void MoveDog();
	sf::Clock gameClock;
	sf::Time gameElapsed;
};

#endif /* GAME_HPP_ */

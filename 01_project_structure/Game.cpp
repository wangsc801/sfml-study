#include "Game.hpp"

Game::Game() : window("project structure", sf::Vector2u(1280, 768))
{
	dogTexture.loadFromFile("asset/img/dog.jpg");
	dogSprite.setTexture(dogTexture);
	dogMoveSpeed = sf::Vector2f(2400, 0);
}

Game::~Game(){};

void Game::Update()
{
	window.Update();
	MoveDog();
}

void Game::Render()
{
	window.BeginDraw();
	window.Draw(dogSprite);
	window.EndDraw();
}

Window *Game::GetWindow()
{
	return &window;
}

sf::Time Game::GetElapsed()
{
	gameElapsed = gameClock.getElapsedTime();
	return gameElapsed;
}

void Game::RestartClock()
{
	gameClock.restart();
}

void Game::MoveDog()
{
	sf::Vector2u windowSize = window.GetWindowSize();
	sf::Vector2u dogTextureSize = dogTexture.getSize();
	if ((dogSprite.getPosition().x > windowSize.x - dogTextureSize.x) || (dogSprite.getPosition().x < 0))
	{
		dogMoveSpeed.x = -dogMoveSpeed.x;
	}
	float fElapsed = gameElapsed.asSeconds();
	dogSprite.setPosition(dogSprite.getPosition().x + dogMoveSpeed.x * fElapsed,
						  dogSprite.getPosition().y);
}

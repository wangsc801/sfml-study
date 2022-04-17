#include "Game.hpp"

int main()
{
	Game game;
	game.GetElapsed();
	float framerate = 1.0f / 60.0f;
	while (!game.GetWindow()->IsDone())
	{
		game.Update();
		game.Render();
		sf::sleep(sf::seconds(framerate));
		game.RestartClock();
	}
	return 0;
}

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
	// default setting for title and window size.
	Window();
	Window(const std::string &title, const sf::Vector2u &size);
	~Window();
	// if sf::Event::Closed triggered, IsDone returns true
	bool IsDone();
	// handle private member: isDone
	void Update();
	void BeginDraw();
	void EndDraw();
	bool IsFullscreen();
	void ToggleFullscreen();
	sf::Vector2u GetWindowSize();
	void Draw(sf::Drawable& drawable);
private:
	void Setup(const std::string &title, const sf::Vector2u &size);
	void Create();
	void Destroy();
	sf::RenderWindow renderWindow;
	sf::Vector2u windowSize;
	std::string windowTile;
	bool isDone;
	bool isFullscreen;
};

#endif /* WINDOW_HPP_ */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	Window(const std::string &title, const sf::Vector2u &size);
	~Window();

	void BeginDraw();
	void Draw(sf::Drawable &drawable);
	void EndDraw();

	void Update();

	// if sf::Event::Closed triggered, IsDone returns true
	bool IsDone();
	bool IsFullscreen();
	void ToggleFullscreen();

	sf::RenderWindow *GetRenderWindow();
	sf::Vector2u GetWindowSize();


private:
	void Setup(const std::string &title, const sf::Vector2u &size);
	void Create();
	void Destroy();

	sf::RenderWindow m_renderWindow;
	sf::Vector2u m_windowSize;
	std::string m_windowTile;
	bool m_isDone;
	bool m_isFullscreen;
};

#endif

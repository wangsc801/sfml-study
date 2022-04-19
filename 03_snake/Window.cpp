#include "Window.hpp"

Window::Window()
{
	Setup("Game", sf::Vector2u(800, 600));
}

Window::Window(const std::string &title, const sf::Vector2u &size)
{
	Setup(title, size);
}

Window::~Window()
{
	Destroy();
}

void Window::BeginDraw()
{
	m_renderWindow.clear(sf::Color::Black);
}

void Window::Draw(sf::Drawable &drawable)
{
	m_renderWindow.draw(drawable);
}

void Window::EndDraw()
{
	m_renderWindow.display();
}

bool Window::IsDone()
{
	return m_isDone;
}

bool Window::IsFullscreen()
{
	return m_isFullscreen;
}

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

sf::RenderWindow *Window::GetRenderWindow()
{
	return &m_renderWindow;
}

sf::Vector2u Window::GetWindowSize()
{
	return m_windowSize;
}

void Window::Setup(const std::string &title, const sf::Vector2u &size)
{
	m_windowTile = title;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void Window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_renderWindow.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTile, style);
	m_renderWindow.setFramerateLimit(60);
}

void Window::Destroy()
{
	m_renderWindow.close();
}

void Window::Update()
{
	sf::Event event;
	while (m_renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_isDone = true;
		}
		else if (event.key.code == sf::Keyboard::Escape)
		{
			m_isDone = true;
		}
		else if (event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}
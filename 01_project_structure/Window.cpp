#include "Window.hpp"

Window::Window() {
	Setup("SFML", sf::Vector2u(1280,768));
}

Window::Window(const std::string &title, const sf::Vector2u &size) {
	Setup(title, size);
}

Window::~Window() {
	Destroy();
}

bool Window::IsDone() {
	return isDone;
}

void Window::Update() {
	sf::Event event;
	while (renderWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			isDone = true;
		} else if (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::F5) {
			ToggleFullscreen();
		}
	}
}

void Window::BeginDraw() {
	renderWindow.clear(sf::Color::Black);
}

void Window::EndDraw() {
	renderWindow.display();
}

bool Window::IsFullscreen() {
	return isFullscreen;
}

void Window::ToggleFullscreen() {
	isFullscreen = !isFullscreen;
	Destroy();
	Create();
}

sf::Vector2u Window::GetWindowSize(){
	return windowSize;
}

void Window::Draw(sf::Drawable& drawable){
	renderWindow.draw(drawable);
}


void Window::Setup(const std::string &title, const sf::Vector2u &size) {
	windowTile = title;
	windowSize = size;
	isFullscreen = false;
	isDone = false;
	Create();
}

void Window::Create() {
	auto style = (isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	renderWindow.create( { windowSize.x, windowSize.y, 32 }, windowTile, style);
	renderWindow.setFramerateLimit(60);
}

void Window::Destroy() {
	renderWindow.close();
}

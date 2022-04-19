#include "Game.hpp"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
               m_world(sf::Vector2u(800, 600))
{
    m_clock.restart();
    srand(time(nullptr));

    m_elapsed = 0.0f;
}

Game::~Game() {}

sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
Window *Game::GetWindow() { return &m_window; }

void Game::Update()
{
    m_window.Update();
}

void Game::Render()
{
    m_window.BeginDraw();
    m_world.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}
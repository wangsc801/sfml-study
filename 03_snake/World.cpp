#include "World.hpp"

World::World(sf::Vector2u l_windSize)
{
    m_blockSize = 16;

    m_windowSize = l_windSize;
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize / 2);
    RespawnApple();

    // boundary wall
    for (int i = 0; i < 4; ++i)
    {
        m_bounds[i].setFillColor(sf::Color(150, 0, 0));
        if (i % 2)
        /*
        index:0   1   2   3
        %2 -> 0   1   0   1

        0: horizontal bar rectangle
        1: vertical bar rectangle
        */
        {
            m_bounds[i].setSize(sf::Vector2f(m_windowSize.x,
                                             m_blockSize));
        }
        else
        {
            m_bounds[i].setSize(sf::Vector2f(m_blockSize,
                                             m_windowSize.y));
        }
        if (i < 2)
        // m_bounds[0] and m_bounds[1] set at left-up corner
        {
            m_bounds[i].setPosition(0, 0);
        }
        else
        // m_bounds[2] and m_bounds[3] set at right-down corner
        {
            m_bounds[i].setOrigin(m_bounds[i].getSize());
            m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
        }
    }
}

World::~World() {}

void World::RespawnApple()
{
    int maxX = (m_windowSize.x / m_blockSize) - 2;
    int maxY = (m_windowSize.y / m_blockSize) - 2;
    srand((int)time(0));
    m_item = sf::Vector2i(
        rand() % maxX + 1, rand() % maxY + 1);
    m_appleShape.setPosition(
        m_item.x * m_blockSize,
        m_item.y * m_blockSize);
}

void World::Render(sf::RenderWindow &l_window)
{
    for (int i = 0; i < 4; ++i)
    {
        l_window.draw(m_bounds[i]);
    }
    l_window.draw(m_appleShape);
}

int World::GetBlockSize() { return m_blockSize; }
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class World
{
public:
    World(sf::Vector2u l_windSize);
    ~World();
    int GetBlockSize();
    void RespawnApple();
    void Render(sf::RenderWindow &l_window);

private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;
    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};

#endif
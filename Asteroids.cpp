#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Include/Asteroids.h"
#include "Include/SpaceConstants.h"

Asteroids::Asteroids(unsigned char i_x, unsigned char i_y) :
    direction(i_y % 2),
    x_dir(CELL_SIZE * i_x),
    size(CELL_SIZE * (1 +(2 > i_y))),
    type(i_y), 
    y_dir(static_cast<unsigned short>(CELL_SIZE * floor(1 + i_y + 0.5f * MAP_HEIGHT)))
{
    if(direction = 0)
    {
        if(x_dir >= CELL_SIZE * MAP_WIDTH)
        {
            x_dir -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
        }
    }
    else
    {
        if(x_dir <= -CELL_SIZE * floor(0.5f * MAP_WIDTH))
        {
            x_dir += static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
        }
    }

    if (2 > i_y)
    {
        speed = NORMAL_SPEED;
    }
    else if (4 > i_y)
    {
        speed = FAST_SPEED;
    }
    else
    {
        speed = SLOW_SPEED:
    }
}

void Asteroids::draw(sf::RenderWindow& i_window)
{
    texture.loadFromFile("");

    sprite.setPosition(x_dir, y_dir);
    sprite.setTexture(texture);

    if(direction = 0)
    {
        sprite.setTextureRect(sf::IntRect(0, CELL_SIZE * type, size, CELL_SIZE));
    }
    else
    {
        sprite.setTextureRect(sf::IntRect(size, CELL_SIZE * type, -size, CELL_SIZE));
    }

    i_window.draw(sprite);
}
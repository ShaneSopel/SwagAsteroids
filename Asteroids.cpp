#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Include/Asteroids.h"
#include "Include/SpaceConstants.h"

using namespace SpaceConstants;

Asteroids::Asteroids()
{
    dx=rand()%8-4;
    dy=rand()%8-4;
    name="asteroid";
}

void Asteroids::update()
{
     x_coord+=dx;
     y_coord+=dy;

     if (x_coord>MAP_WIDTH1) x_coord=0;  if (x_coord<0) x_coord=MAP_WIDTH1;
     if (y_coord>MAP_WIDTH1) y_coord=0;  if (y_coord<0) y_coord=MAP_HEIGHT1;
}

sf::IntRect Asteroids::get_rect() const
{
    return sf::IntRect(x_coord, y_coord, CELL_SIZE, CELL_SIZE);
}

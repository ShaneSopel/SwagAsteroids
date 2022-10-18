#include <cmath>
#include <list>
#include <SFML/Graphics.hpp>

#include "Include/Bullet.h"
#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"

using namespace SpaceConstants;

Bullet::Bullet()
{
    name = "bullet";
}

void Bullet::update()
{
    dx=cos(angle*DEGTORAD)*6;
    dy=sin(angle*DEGTORAD)*6;
     // angle+=rand()%7-3;  /*try this
     x_coord+=dx;
     y_coord+=dy;

     if (x_coord>MAP_WIDTH1 || x_coord<0 || y_coord>MAP_HEIGHT1 || y_coord<0) life=0; 
}

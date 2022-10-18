#ifndef BULLET_H
#define BULLET_H

#include <list>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "SpaceShip.h"

class Bullet: public Entity 
{
    public:

     // Spaceship control keys. 
     bool shoot_key;


    Bullet();
    void update();
};

#endif
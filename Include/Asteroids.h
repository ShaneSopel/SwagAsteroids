#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Asteroids : public Entity 
{
   
public:
    Asteroids();
    void update();

};

#endif

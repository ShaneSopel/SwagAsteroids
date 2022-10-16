#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Asteroids : public Entity 
{
   
public:
    Asteroids();
    void update();
    sf::IntRect get_rect() const;
};

#endif

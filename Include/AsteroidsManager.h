# ifndef ASTEROIDS_MANAGER_H
#define ASTEROIDS_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "SpaceShip.h"

class AsteroidsManager
{
    std::vector<Asteroids> asteroidsManager;

public:
    AsteroidsManager(unsigned char i_level);

    void draw(sf::RenderWindow& i_window);
    void generate_level(unsigned char i_level);
    void update(SpaceShip& i_spaceship);
};

#endif

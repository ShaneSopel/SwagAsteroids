# ifndef ASTEROIDS_MANAGER_H
#define ASTEROIDS_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "SpaceShip.h"

class AsteroidsManager
{
    std::vector<AsteroidsManager> asteroidsManager;

public:
    AsteroidsManager();

    void draw(sf::RenderWindow& i_window);
    void generate_level(unsigned char i_level);
    void update(SpaceShip& i_spaceship);
};

#endif

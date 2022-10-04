#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <SFML/Graphics.hpp>

class Asteroids 
{
    bool direction;

    // X and Y Axis
    short x_dir;
    unsigned short y_dir;

    // Astroid Variables 
    unsigned char size;
    unsigned char speed;
    unsigned char type;

    // Create Sprite
    sf::Sprite sprite;

    // Create Texture
    sf::Texture texture;

public:
    Asteroids(unsigned char i_x, unsigned char i_y);

    void draw(sf::RenderWindow& i_window);
    void update();

    sf::IntRect get_rect() const;
};

#endif

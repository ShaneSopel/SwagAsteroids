#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include <array>
#include <SFML/Graphics.hpp>

class SpaceShip
{
    // X and Y Axis
    short x_dir;
    unsigned short y_dir;

    // bool for if Spaceship is destroyed.
    bool destroyed;

    unsigned char animation_timer;
    unsigned char current_frame;
    unsigned char direction;

    // Spaceship control keys. 
    std::array<bool, 4> control_keys;

    // Create Sprite
    sf::Sprite sprite;

    // Create Texture
    sf::Texture texture;

public:

    SpaceShip();

    bool get_Destroyed() const;

    bool update_space(std::array<bool, 5>& i_space);

    unsigned short get_y();

    void draw(sf::RenderWindow& i_window);
    void move(char i_value);
    void reset();
    void set_Destroyed();
    void update();

    sf::IntRect get_rect() const;
};

#endif

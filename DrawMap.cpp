#include <iostream>
#include <SFML/Graphics.hpp>

#include "Include/DrawMap.h"
#include "Include/SpaceConstants.h"

using namespace SpaceConstants;
void draw_map(sf::RenderWindow& i_window)
{
    sf::Sprite sprite;
    sf::Texture texture;

    if(!texture.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Images/space.png"))
    {
        std::cout << "error";
    }
    sprite.setTexture(texture);

    i_window.draw(sprite);
}

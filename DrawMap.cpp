#include <iostream>
#include <SFML/Graphics.hpp>

#include "Include/DrawMap.h"
#include "Include/SpaceConstants.h"

using namespace SpaceConstants;
void Draw_map(sf::RenderWindow& i_window)
{
    sf::Sprite sprite;
    sf::Texture texture;

    if(!texture.loadFromFile("./../Resources/Images/space.png"))
    {
        std::cout << "error";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);

    i_window.draw(sprite);
}

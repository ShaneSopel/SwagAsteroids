#ifndef MENU_H
#define MENU_H

#define MAX_NUMBER_OF_ITEMS 3

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Menu
{
    private:
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];
    sf::Sprite swag;
    sf::Texture swaglogo;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;
    bool m_isOptionsButtonSelected;
    bool m_isOptionsButtonPressed;
    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

    public:
    Menu(float Width, float Height);
    ~Menu();

    void Draw(sf::RenderWindow &window);
    void ProcessInput(sf::RenderWindow &window, sf::Event event);
    void Update(sf::RenderWindow &window,  GameObject &game);

};

#endif 
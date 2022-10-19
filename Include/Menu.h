#ifndef MENU_H
#define MENU_H

#define MAX_NUMBER_OF_ITEMS 3

#include <SFML/Graphics.hpp>

class Menu
{
    
    int SelectedItemIndex;

    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];

    public:
    Menu(float Width, float Height);
    ~Menu();

    void MoveUp();
    void MoveDown();
    void draw(sf::RenderWindow &window);

};

#endif 
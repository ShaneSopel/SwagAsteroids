#ifndef GAMEOVER_H
#define GAMEOVER_H

#define MAX_NUMBER_OF_ITEMS 3

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class GameOver
{
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];
    sf::Sprite swag;
    sf::Texture swaglogo;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;
    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

    public:
    GameOver(float Width, float Height);
    ~GameOver();

    void Draw(sf::RenderWindow &window);
    void ProcessInput(sf::RenderWindow &window, sf::Event event);
    void Update(sf::RenderWindow &window,  GameObject &game);
    void SetGameOver(GameObject &game);

};

#endif 
#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

class TextManager
{
    private:
     std::string FONT_PATH = "bin/Assets/Fonts/";
     std::list<sf::Text*> texts;
     sf::Text textContent;

    public:
    sf::Font font;
    void LoadFont();
    void TypeText(std::string text, sf::Color fontColor, sf::Vector2f position);
    void Draw(sf::RenderTarget &window);
     
};

#endif
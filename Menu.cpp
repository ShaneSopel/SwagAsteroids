#include <iostream>

#include "Include/GameObject.h"
#include "Include/DrawMap.h"
#include "Include/Menu.h"

#include "SpaceConstants.h"

using namespace SpaceConstants;

Menu::Menu(float width, float height)
: m_isPlayButtonSelected(true), m_isPlayButtonPressed(false), m_isOptionsButtonSelected(false),
      m_isOptionsButtonPressed(false), m_isExitButtonSelected(false), m_isExitButtonPressed(false)
{
    if(!font.loadFromFile("./../Resources/Images/ARCADE.TTF"))
    {

    }
   
    swaglogo.loadFromFile("./../Resources/Images/Asteroids.png");
    swag.setTexture(swaglogo);

    // Play Button
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Play");
    text[0].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

    // Options Button
    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Options");
    text[1].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    // Exit Button
    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Exit");
    text[2].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.5));

}

Menu::~Menu()
{

}

void Menu::ProcessInput(sf::RenderWindow &window ,sf::Event event)
{
    while (window.pollEvent(event))
    {
                if (event.type == sf::Event::Closed)
                window.close();

          
    switch (event.key.code)
    {
        case sf::Keyboard::Up:
        {
            if (!m_isPlayButtonSelected)
            {
                m_isPlayButtonSelected = true;
                m_isOptionsButtonSelected = false;
                m_isExitButtonSelected = false;
            }
         /*   else if (!m_isOptionsButtonSelected)
            {
                m_isPlayButtonSelected = false;
                m_isOptionsButtonSelected = true;
                m_isExitButtonSelected = false;
            }*/

            break;
        }
        case sf::Keyboard::Down:
        {

           /* if (!m_isOptionsButtonSelected)
            {
                m_isPlayButtonSelected = false;
                m_isOptionsButtonSelected = true;
                m_isExitButtonSelected = false;
            }*/
             if (!m_isExitButtonSelected)
            {
                m_isPlayButtonSelected = false;
                m_isOptionsButtonSelected = false;
                m_isExitButtonSelected = true;
            }

            break;
        }
        case sf::Keyboard::Return:
        {
                    
            m_isPlayButtonPressed = false;
            m_isExitButtonPressed = false;
            m_isOptionsButtonPressed = false;

            if (m_isPlayButtonSelected)
            {
                m_isPlayButtonPressed = true;
            }
            //  else if(m_isOptionsButtonSelected)
            //  {
            //      m_isOptionsButtonPressed = true;
            //  }
            else
            {
                m_isExitButtonPressed = true;
            }
            break;
        }
        default:
        {
            break;
        }
     }
    }
}

void Menu::Update(sf::RenderWindow &window, GameObject& game)
{
    if (m_isPlayButtonSelected)
    {
        text[0].setFillColor(sf::Color::Red);
        text[1].setFillColor(sf::Color::White);
        text[2].setFillColor(sf::Color::White);
    }
    else if (m_isExitButtonSelected)
    {
        text[0].setFillColor(sf::Color::White);
        text[1].setFillColor(sf::Color::White);
        text[2].setFillColor(sf::Color::Red);
    }

    if (m_isPlayButtonPressed)
    {
        game.SetState(STATE::level1);
    }

    if (m_isExitButtonPressed)
    {
        window.close();
    }
}


void Menu::Draw(sf::RenderWindow &window)
{

    window.clear();
    Draw_map(window);
    window.draw(swag);


    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(text[i]);
    }

    window.display();

}
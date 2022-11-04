#include <iostream>

#include "Include/GameObject.h"
#include "Include/DrawMap.h"
#include "Include/GameOver.h"

#include "SpaceConstants.h"

using namespace SpaceConstants;

GameOver::GameOver(float width, float height)
: m_isPlayButtonSelected(true), m_isPlayButtonPressed(false), 
m_isExitButtonSelected(false), m_isExitButtonPressed(false)
{
    if(!font.loadFromFile("./../Resources/Images/ARCADE.TTF"))
    {

    }
   
    swaglogo.loadFromFile("./../Resources/Images/GameOver.png");
    swag.setTexture(swaglogo);

    // Play Button
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Play Again");
    text[0].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    // Exit Button
    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Exit");
    text[2].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

}


GameOver::~GameOver()
{

}

void GameOver::ProcessInput(sf::RenderWindow &window ,sf::Event event)
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
                m_isExitButtonSelected = false;
            }
            break;
        }
        case sf::Keyboard::Down:
        {
             if (!m_isExitButtonSelected)
            {
                m_isPlayButtonSelected = false;
                m_isExitButtonSelected = true;
            }

            break;
        }
        case sf::Keyboard::Return:
        {
                    
            m_isPlayButtonPressed = false;
            m_isExitButtonPressed = false;
       

            if (m_isPlayButtonSelected)
            {
                m_isPlayButtonPressed = true;
            }

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

void GameOver::Update(sf::RenderWindow &window, GameObject& game)
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


void GameOver::Draw(sf::RenderWindow &window)
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
   
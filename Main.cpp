#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "Include/Animation.h"
#include "Include/Entity.h"
#include "Include/GameObject.h"
#include "Include/GameOver.h"
#include "Include/LevelManager.h"
#include "Include/Menu.h"
#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"
#include "Include/TextManager.h"

using namespace SpaceConstants;

int main()
{
    Menu menu(MAP_WIDTH1, MAP_HEIGHT1);
    LevelManager level(MAP_WIDTH1, MAP_HEIGHT1);
    LevelManager level2(MAP_WIDTH1, MAP_HEIGHT1);
    GameOver gover(MAP_WIDTH1, MAP_HEIGHT1);

    GameObject game;

    sf::Music music;    
    music.openFromFile("./..//Resources/Sounds/SwagAsteroidsTheme.wav");
    music.setVolume(75);
    music.play();

    game.SetState(0);
    game.setAnimation();
    Animation sRock = game.getRock();
    Animation sSpaceShip = game.getSpaceShip();
    Animation sBullet = game.getBullet();
    Animation sExplosion = game.getExplosion();

    std::list<Entity *> entities;

    level.AsteroidHandler(sRock, entities);
 
    SpaceShip *p = new SpaceShip();
    p->settings(sSpaceShip, 400, 400, 0, 20);
    entities.push_back(p);

    sf::RenderWindow mainMenu(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
    mainMenu.setFramerateLimit(60);

    while (mainMenu.isOpen())
    {

        sf::Event event;
        if (game.GetState() == STATE::menu)
        {
            menu.ProcessInput(mainMenu, event);
            menu.Update(mainMenu, game);
            menu.Draw(mainMenu);
        }

        if (game.GetState() == STATE::level1)
        {
            sf::RenderWindow level1(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
            sf::Event event1;
            while (level1.isOpen())
            {
                level.ProcessInput(level1, event1, entities, sBullet, p);
                level.Update(level1, game, entities, p, sSpaceShip, sExplosion);
                level.Draw(level1,game, entities, p);

                mainMenu.close();

                if (game.GetState() == STATE::level2)
                {
                    std::cout << "made it to level2";
                    sf::RenderWindow level2(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
                    sf::Event event2;
                    level1.close();
                    level.AsteroidHandler(sRock, entities);
                
                    while (level2.isOpen())
                    {
                        level.ProcessInput(level2, event2, entities, sBullet, p);
                        level.Update(level2, game, entities, p, sSpaceShip, sExplosion);
                        level.Draw(level2,game, entities, p);
                    }

                    if (game.GetState() == STATE::level3)
                    {
                        std::cout << "made it to level3";
                        sf::RenderWindow level3(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
                        sf::Event event3;
                        level2.close();
                        level.AsteroidHandler(sRock, entities);
                    
                        while (level3.isOpen())
                        {
                            level.ProcessInput(level3, event3, entities, sBullet, p);
                            level.Update(level3, game, entities, p, sSpaceShip, sExplosion);
                            level.Draw(level3,game, entities, p);

                            if (game.GetState() == STATE::GAMEOVER)
                            {
                                std::cout << "made it here";
                                sf::RenderWindow GameOver(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
                                sf::Event over;
                                level1.close();
                                level2.close();
                                level3.close();

                                while (GameOver.isOpen())
                                {
                                    gover.ProcessInput(GameOver, over);
                                    gover.Update(GameOver, game);
                                    gover.Draw(GameOver);
                                }
                            }
                        }
                    }
                }   
            }
        }
    }
}
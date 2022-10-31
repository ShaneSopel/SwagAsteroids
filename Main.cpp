#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Include/Asteroids.h"
#include "Include/Animation.h"
#include "Include/Bullet.h"
#include "Include/Collision.h"
#include "Include/DrawMap.h"
#include "Include/Entity.h"
#include "Include/GameObject.h"
#include "Include/GameOver.h"
#include "Include/Menu.h"
#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"
#include "Include/TextManager.h"

using namespace SpaceConstants;

   void setlevel(int val, Animation & sRock, std::list<Entity*> &entities)
    {
        for (int i = 0; i < val; i++)
        {
            Asteroids *a = new Asteroids();
            a->settings(sRock, rand() % MAP_WIDTH1, rand() % MAP_HEIGHT1, rand() % 360, 25);
            entities.push_back(a);
        }
    }


int main()
{
    unsigned char level = 0;

    Menu menu(MAP_WIDTH1, MAP_HEIGHT1);
    GameOver gover(MAP_WIDTH1, MAP_HEIGHT1);

    GameObject game;

    sf::Music music;

    TextManager oneuptext;
    TextManager HighScore;
    TextManager Lives;
    oneuptext.loadFont();
    HighScore.loadFont();
    Lives.loadFont();

    music.openFromFile("/home/shanes/c++/SwagAsteroids/Resources/Sounds/Triumph.flac");
    music.setVolume(75);

    music.play();

    game.SetState(0);
    game.setAnimation();
    Animation sRock = game.getRock();
    Animation sSpaceShip = game.getSpaceShip();
    Animation sBullet = game.getBullet();
    Animation sExplosion = game.getExplosion();

    std::list<Entity *> entities;

    setlevel(1, sRock, entities);

    SpaceShip *p = new SpaceShip();
    p->settings(sSpaceShip, 400, 400, 0, 20);
    entities.push_back(p);

    sf::RenderWindow mainMenu(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
    mainMenu.setFramerateLimit(60);

    while (mainMenu.isOpen())
    {

        sf::Event event;
        if (game.GetState() == 0)
        {
            menu.ProcessInput(mainMenu, event);
            menu.Update(mainMenu, game);
            menu.draw(mainMenu);
        }

        if (game.GetState() == 1)
        {
            sf::RenderWindow play(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
            sf::Event event1;
            while (play.isOpen())
            {
                std::ostringstream p1Score;
                std::ostringstream highscoreIn;
                std::ostringstream livesIn;
                p1Score << "1UP "
                        << "\n"
                        << p->GetScore();
                highscoreIn << "Highscore "
                            << "\n"
                            << "1000000";
                livesIn << "Lives "
                        << "\n"
                        << p->GetLives();
                oneuptext.typeText(p1Score.str(), sf::Color::Red, {30, 30});
                HighScore.typeText(highscoreIn.str(), sf::Color::Red, {325, 30});
                Lives.typeText(livesIn.str(), sf::Color::Red, {675, 30});

                while (play.pollEvent(event1))
                {
                    if (event1.type == sf::Event::Closed)
                        play.close();

                    if (event1.key.code == sf::Keyboard::Space)
                    {
                        Bullet *b = new Bullet();
                        b->settings(sBullet, p->x_coord, p->y_coord, p->angle, 10);
                        entities.push_back(b);
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    p->angle += 3;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    p->angle -= 3;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    p->thrust = true;
                else
                    p->thrust = false;

                for (auto a : entities)
                {

                    for (auto b : entities)
                    {
                        if (a->name == "asteroid" && b->name == "bullet")
                            if (isCollide(a, b))
                            {
                                a->life = false;
                                b->life = false;

                                Entity *e = new Entity();
                                e->settings(sExplosion, a->x_coord, a->y_coord, 0, 0);
                                e->name = "explosion";
                                entities.push_back(e);

                                p->SetScore(10);
                            }

                        if (a->name == "SpaceShip" && b->name == "asteroid")
                            if (isCollide(a, b))
                            {
                                b->life = false;

                                Entity *e = new Entity();
                                e->settings(sExplosion, a->x_coord, a->y_coord, a->angle, a->R);
                                e->name = "explosion";
                                entities.push_back(e);

                                p->settings(sSpaceShip, MAP_WIDTH1 / 2, MAP_HEIGHT1 / 2, 0, 20);
                                p->dx = 0;
                                p->dy = 0;

                                p->SetLives(1);
                            }
                    }
                }

                if (p->thrust)
                {
                    p->anim = sSpaceShip;
                }
                else
                {
                    p->anim = sSpaceShip;
                }

                for (auto e : entities)
                {
                    if (e->name == "explosion")
                    {
                        if (e->anim.isEnd())
                        {
                            e->life = 0;
                        }
                    }
                }

                for (auto i = entities.begin(); i != entities.end();)
                {
                    Entity *e = *i;
                    e->update();
                    e->anim.update();

                    if (e->life == false)
                    {
                        i = entities.erase(i);
                        delete e;
                    }
                    else
                        i++;
                }

                play.clear();

                draw_map(play);
                oneuptext.draw(play);
                HighScore.draw(play);
                Lives.draw(play);

                for (auto i : entities)
                    i->draw(play);
                play.display();

                if (p->GetLives() == 0)
                {
                    game.SetState(2);
                    play.close();
                    break;
                }

                mainMenu.close();
            }

            if (game.GetState() == 2)
            {
                std::cout << "made it here";
                sf::RenderWindow GameOver(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids");
                sf::Event over;

                while (GameOver.isOpen())
                {
                    gover.ProcessInput(GameOver, over);
                    gover.Update(GameOver, game);
                    gover.draw(GameOver);
                }
            }
        }
    }
}
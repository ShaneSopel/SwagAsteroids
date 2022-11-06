#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

#include "Include/Asteroids.h"
#include "Include/GameObject.h"
#include "Include/DrawMap.h"
#include "Include/LevelManager.h"

#include "Include/SpaceConstants.h"

using namespace SpaceConstants;

LevelManager::LevelManager(float width, float height)
: m_AsteroidNum(5)
{
    oneuptext.LoadFont();
    HighScore.LoadFont();
    Lives.LoadFont();
    AsteroidsRemain.LoadFont();
    Levels.LoadFont();
    sound.LoadSound();
    swaglogo.loadFromFile("./../Resources/Images/Asteroids.png");
    swag.setTexture(swaglogo);
}

LevelManager::~LevelManager()
{
}

void LevelManager::ProcessInput(sf::RenderWindow &play ,sf::Event event, std::list<Entity *> &entities, Animation sBullet, SpaceShip *p)
{
    
    while (play.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            play.close();

        if ((event.key.code == sf::Keyboard::Space) && (event.type == sf::Event::KeyReleased))
        {
            sound.getLaser();
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

}

void LevelManager::Update(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities, SpaceShip *p, Animation sSpaceShip, Animation sExplosion)
{

    ScoreHandler(p);
    CollisionHandler(sSpaceShip,  entities, sExplosion, p);
    ThrustHandler(sSpaceShip, p);
    LifeHandler(entities);

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

    LevelHandler(game, play);
}

void LevelManager::Draw(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities, SpaceShip *p)
{

    play.clear();
    Draw_map(play);
    oneuptext.Draw(play);
    HighScore.Draw(play);
    Lives.Draw(play);
    AsteroidsRemain.Draw(play);

    for (auto i : entities)
        i->draw(play);
        play.display();

    if (p->GetLives() == 0)
    {
        game.SetState(STATE::GAMEOVER);
        play.close();
    }
}

void LevelManager::AsteroidHandler(Animation & sRock, std::list<Entity*> &entities)
{
    for (int i = 0; i < m_AsteroidNum; i++)
    {
        Asteroids *a = new Asteroids();
        a->settings(sRock, rand() % MAP_WIDTH1, rand() % MAP_HEIGHT1, rand() % 360, 25);
        entities.push_back(a);
    }
}

void LevelManager::CollisionHandler(Animation sSpaceShip,  std::list<Entity *> &entities, Animation sExplosion, SpaceShip *p)
{
        for (auto a : entities)
    {
                for (auto b : entities)
                {
                    if (a->name == "asteroid" && b->name == "bullet")
                        if (Collide(a, b))
                        {
                            a->life = false;
                            b->life = false;

                            Entity *e = new Entity();
                            e->settings(sExplosion, a->x_coord, a->y_coord, 0, 0);
                            e->name = "explosion";
                            entities.push_back(e);
                            sound.getExplosion();

                            m_AsteroidNum--;
                            p->SetScore(10);
                        }

                    if (a->name == "SpaceShip" && b->name == "asteroid")
                        if (Collide(a, b))
                        {
                            b->life = false;

                            Entity *e = new Entity();
                            e->settings(sExplosion, a->x_coord, a->y_coord, a->angle, a->R);
                            e->name = "explosion";
                            entities.push_back(e);
                            p->settings(sSpaceShip, MAP_WIDTH1 / 2, MAP_HEIGHT1 / 2, 0, 20);
                            p->dx = 0;
                            p->dy = 0;
                            sound.getSpaceShipDead();

                            p->SetLives(1);
                            m_AsteroidNum--;
                        }
                }
        }
}

void LevelManager::LevelHandler(GameObject &game, sf::RenderWindow &play)
{
    if(m_AsteroidNum == 0)
    { 
            m_LevelUp++;   
            
            if (m_LevelUp == 2)
            {
                std::cout << "level2";
                SplashScreen(play);
                m_AsteroidNum = 10;
                game.SetState(STATE::level2);
            }
            if (m_LevelUp == 3)
            {
                std::cout << "level3";
                SplashScreen(play);
                m_AsteroidNum = 15;
                game.SetState(STATE::level3);
            }
    }        
}

void LevelManager::LifeHandler(std::list<Entity *> &entities)
{
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
}


void LevelManager::ScoreHandler( SpaceShip *p)
{
    std::ostringstream p1Score;
    std::ostringstream highscoreIn;
    std::ostringstream livesIn;
    std::ostringstream AsteroidsIn;
    std::ostringstream LevelsIn;
    int m_LevelUp1 = m_LevelUp;
    LevelsIn << "Level: " << m_LevelUp1 + 1 ;
    p1Score << "1UP "
            << "\n"
            << p->GetScore();
    highscoreIn << "Highscore "
                << "\n"
                << "1000000";
    livesIn << "Lives "
            << "\n"
            << p->GetLives();
    AsteroidsIn << "Asteroids: " << m_AsteroidNum;
    oneuptext.TypeText(p1Score.str(), sf::Color::Red, {30, 30});
    HighScore.TypeText(highscoreIn.str(), sf::Color::Red, {325, 30});
    Lives.TypeText(livesIn.str(), sf::Color::Red, {675, 30});
    AsteroidsRemain.TypeText(AsteroidsIn.str(), sf::Color::Red, {10,550});
    Levels.TypeText(LevelsIn.str(), sf::Color::Red, {325,325});
}

void LevelManager::ThrustHandler(Animation sSpaceShip, SpaceShip *p)
{
     if (p->thrust)
    {
        p->anim = sSpaceShip;
    }
    else
    {
        p->anim = sSpaceShip;
    }

}

void LevelManager::SplashScreen(sf::RenderWindow &play)
{
    play.clear();
    Draw_map(play);
    play.draw(swag);
    Levels.Draw(play);
    play.display();
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
} 
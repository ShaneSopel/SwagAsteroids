#include <iostream>
#include <sstream>

#include "Include/Asteroids.h"
#include "Include/GameObject.h"
#include "Include/DrawMap.h"
#include "Include/Level.h"

#include "Include/SpaceConstants.h"

using namespace SpaceConstants;

Level::Level(float width, float height)
: m_AsteroidNum(5)
{
}

Level::~Level()
{
}

void Level::ProcessInput(sf::RenderWindow &play ,sf::Event event, sf::Sound &Lasersound, std::list<Entity *> &entities, Animation sBullet, SpaceShip *p)
{
    
    while (play.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            play.close();

        if (event.key.code == sf::Keyboard::Space)
        {
            Lasersound.play();
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

void Level::Update(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities, TextManager &oneuptext, TextManager &HighScore, TextManager &Lives, SpaceShip *p, Animation sSpaceShip, Animation sExplosion, sf::Sound &Explosionsound1, TextManager &AsteroidsRemain)
{

    ScoreHandler( oneuptext, HighScore, Lives, AsteroidsRemain, p);
    CollisionHandler(sSpaceShip,  entities, sExplosion, Explosionsound1, p);
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

    
}

void Level::Draw(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities, TextManager &oneuptext, TextManager &HighScore, TextManager &Lives, TextManager &AsteroidsRemain, SpaceShip *p)
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
        game.SetState(2);
        play.close();
    }
}

void Level::AsteroidHandler(Animation & sRock, std::list<Entity*> &entities)
{
    for (int i = 0; i < m_AsteroidNum; i++)
    {
        Asteroids *a = new Asteroids();
        a->settings(sRock, rand() % MAP_WIDTH1, rand() % MAP_HEIGHT1, rand() % 360, 25);
        entities.push_back(a);
    }
}

void Level::CollisionHandler(Animation sSpaceShip,  std::list<Entity *> &entities, Animation sExplosion, sf::Sound &Explosionsound1, SpaceShip *p)
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
                            Explosionsound1.play();
                            // val--
                            //std::cout<< val << std::endl;
                            m_AsteroidNum--;
                            p->SetScore(10);

                            //if (val == 0)
                            //{
                            //    std::cout << "level complete" << std::endl;
                            //}
                        }

                    if (a->name == "SpaceShip" && b->name == "asteroid")
                        if (Collide(a, b))
                        {
                            b->life = false;

                            Entity *e = new Entity();
                            e->settings(sExplosion, a->x_coord, a->y_coord, a->angle, a->R);
                            e->name = "explosion";
                            p->settings(sSpaceShip, MAP_WIDTH1 / 2, MAP_HEIGHT1 / 2, 0, 20);
                            p->dx = 0;
                            p->dy = 0;

                            p->SetLives(1);
                        }
                }
        }
}


void Level::LifeHandler(std::list<Entity *> &entities)
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


void Level::ScoreHandler(TextManager &oneuptext, TextManager &HighScore, TextManager &Lives, TextManager &AsteroidsRemain, SpaceShip *p)
{
    std::ostringstream p1Score;
    std::ostringstream highscoreIn;
    std::ostringstream livesIn;
    std::ostringstream AsteroidsIn;
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
}

void Level::ThrustHandler(Animation sSpaceShip, SpaceShip *p)
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





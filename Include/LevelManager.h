#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Collision.h"
#include "Entity.h"
#include "GameObject.h"
#include "SoundManager.h"
#include "SpaceShip.h"
#include "TextManager.h"

class LevelManager
{
    sf::Font font;
    sf::Sprite swag;
    sf::Texture swaglogo;

    SoundManager sound;
    sf::SoundBuffer sblaser;
    sf::SoundBuffer sbExplosion;
    sf::Sound Lasersound;
    sf::Sound Explosionsound1; 


    TextManager oneuptext;
    TextManager HighScore;
    TextManager AsteroidsRemain;
    TextManager Lives;

    int m_AsteroidNum;

    public:
    LevelManager(float Width, float Height);
    ~LevelManager();

    void AsteroidHandler( Animation & sRock, std::list<Entity*> &entities);
    void CollisionHandler(Animation sSpaceShip,  std::list<Entity *> &entities, Animation sExplosion, SpaceShip *p);
    void LifeHandler(std::list<Entity *> &entities);
    void ScoreHandler( SpaceShip *p);
    void ThrustHandler(Animation sSpaceShip, SpaceShip *p);

    void Draw(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities,  SpaceShip *p);
    void ProcessInput(sf::RenderWindow &play ,sf::Event event, std::list<Entity *> &entities, Animation sBullet, SpaceShip *p);
    void Update(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities,  SpaceShip *p,
     Animation sSpaceShip, Animation sExplosion);

};

#endif 
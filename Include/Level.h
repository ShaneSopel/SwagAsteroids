#ifndef LEVEL_H
#define LEVEL_H

#include <list>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Collision.h"
#include "Entity.h"
#include "GameObject.h"
#include "SpaceShip.h"
#include "TextManager.h"

class Level
{
    sf::Font font;
    sf::Sprite swag;
    sf::Texture swaglogo;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;
    bool m_isOptionsButtonSelected;
    bool m_isOptionsButtonPressed;
    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

    public:
    Level(float Width, float Height);
    ~Level();

    void draw(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities, TextManager &oneuptext, TextManager &HighScore, TextManager &Lives, SpaceShip *p);
    void ProcessInput(sf::RenderWindow &play ,sf::Event event, sf::Sound &Lasersound, std::list<Entity *> &entities, Animation sBullet, SpaceShip *p);
    void Update(sf::RenderWindow &play, GameObject& game, std::list<Entity *> &entities, TextManager &oneuptext, TextManager &HighScore, TextManager &Lives, SpaceShip *p, Animation sSpaceShip, Animation sExplosion, sf::Sound &Explosionsound1 );

};

#endif 
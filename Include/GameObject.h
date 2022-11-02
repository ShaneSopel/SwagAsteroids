#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Animation.h"

enum STATE
{
    menu = 0,
    level1,
    level2,
    level3,
    level4,
    level5,
    GAMEOVER
};

class GameObject
{

    sf::Texture t1;
    sf::Texture t2;
    sf::Texture t3;
    sf::Texture t4;

    Animation Rock;
    Animation Bullet;
    Animation Spaceship;
    Animation Explosion;

    public:
    GameObject();
    void CreateTexture();
    void setAnimation();
    Animation getRock();
    Animation getBullet();
    Animation getSpaceShip();
    Animation getExplosion();

    void SetState(int sstate);
    int GetState();

    int state;

};

#endif
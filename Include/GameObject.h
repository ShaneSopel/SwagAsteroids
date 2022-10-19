#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

#include "Animation.h"

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
    void InitializeAsteroids(std::list<Entity*> entities);
    void setAnimation();
    Animation getRock();
    Animation getBullet();
    Animation getSpaceShip();
    Animation getExplosion();

};

#endif
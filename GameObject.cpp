#include <list>

#include "Include/Asteroids.h"
#include "Include/Entity.h"
#include "Include/GameObject.h"
#include "Include/SpaceConstants.h"

using namespace SpaceConstants;

GameObject::GameObject()
{
    
    t1.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Images/rock.png");
    Animation sRock(t1, 0,0, 64, 64, 16, 0.2);

    t2.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Images/fire_blue.png");
    Animation sBullet(t2, 0,0,32,64, 16, 0.8);

    t3.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Images/Starship3.png");
    Animation sSpaceShip(t3, 40,0,52,52, 1, 0);

    t4.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Images/type_C.png");
    Animation sExplosion(t4, 0,0,256,256, 48, 0.5);
    
    t3.setSmooth(true);
}

void GameObject::setAnimation()
{
    Animation sRock(t1, 0,0, 64, 64, 16, 0.2);
    Rock = sRock;
    Animation sBullet(t2, 0,0,32,64, 16, 0.8);
    Bullet = sBullet;
    Animation sSpaceShip(t3, 40,0,52,52, 1, 0);
    Spaceship = sSpaceShip;
    Animation sExplosion(t4, 0,0,256,256, 48, 0.5);
    Explosion = sExplosion;
}

Animation GameObject::getRock()
{
    return Rock;
}

Animation GameObject::getBullet()
{
    return Bullet;
}

Animation GameObject::getSpaceShip()
{
    return Spaceship;
}

Animation GameObject::getExplosion()
{
    return Explosion;
}

int GameObject::GetState()
{
    return state;
}

void GameObject::SetState(int sstate)
{
    state = sstate;
}

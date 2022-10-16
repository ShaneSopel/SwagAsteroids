#include <SFML/Graphics.hpp>

#include "Include/Bullet.h"
#include "Include/SpaceShip.h"

Bullet::Bullet(sf::Vector2f size)
{
    bullet.setSize(size);
}

/*void::Bullet::setDirection(IntRect direction)
{

}*/

void Bullet::fire(int speed)
{
    bullet.move(speed, 0);
}

#include <SFML/Graphics.hpp>

#include "Include/Entity.h"
#include "Include/Animation.h"

Entity::Entity()
{
    life = true;
}

void Entity::settings(Animation &a,int x_coord1,int y_coord1,float Angle=0,int radius=1)
{
    anim = a;
    x_coord = x_coord1;
    y_coord = y_coord1;
    angle = Angle;
    R = radius;
}

void Entity::draw(sf::RenderWindow &app)
{
    anim.sprite.setPosition(x_coord,y_coord);
    anim.sprite.setRotation(angle+90);
    app.draw(anim.sprite);

    sf::CircleShape circle(R);
    circle.setFillColor(sf::Color(255,0,0,170));
    circle.setPosition(x_coord,y_coord);
    circle.setOrigin(R,R);
}
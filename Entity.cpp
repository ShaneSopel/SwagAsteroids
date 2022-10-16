#include "include/Entity.h"

Entity::Entity()
{
    life = true;
}

void Entity::settings(Animation &a,int X,int Y,float Angle=0,int radius=1)
{
    anim = a;
    x_coord = X;
    y_coord = Y;
    angle = Angle;
    R = radius;
}

virtual void Entity::update()
{

}

virtual ~Entity::Entity()
{

}

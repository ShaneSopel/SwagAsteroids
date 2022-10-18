#include "Include/Collision.h"

#include "Include/Entity.h"

bool isCollide(Entity *a, Entity *b)
{
  return (b->x_coord - a->x_coord)*(b->x_coord - a->x_coord)+
         (b->y_coord - a->y_coord)*(b->y_coord - a->y_coord)<
         (a->R + b->R)*(a->R + b->R);
}



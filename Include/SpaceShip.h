#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include <array>
#include <SFML/Graphics.hpp>

#include "Entity.h"

class SpaceShip : public Entity
{
    // X and Y Axis
    short x_dir;
    unsigned short y_dir;
    

public:

    bool thrust;
    SpaceShip();
    bool get_Destroyed() const;
    void update();

};

#endif

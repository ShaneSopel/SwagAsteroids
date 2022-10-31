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

    int m_score = 0;
    int m_lives = 3;
    
public:

    bool thrust;
    SpaceShip();
    bool get_Destroyed() const;
    int GetScore();
    int GetLives();
    void SetScore(int score);
    void SetLives(int lives);
    
    void update();
};

#endif

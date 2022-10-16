#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "Animation.h"

class Entity
{
    public:
    float x_coord;
    float y_coord;
    float dx;
    float dy;
    float R;
    float angle;

    bool life;
    std::string name;

    Animation anim;

    Entity();
    void settings(Animation &a,int x_coord1,int y_coord1,float Angle,int radius);
    virtual void update(){};
    virtual ~Entity(){};
    void draw(sf::RenderWindow &app);

};

#endif
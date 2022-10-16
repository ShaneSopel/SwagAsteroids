#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

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
    void settings(Animation &a,int x_coord,int y_coord,float Angle=0,int radius=1);
    virtual void update();
    virtual ~Entity();
    void draw();

};

#endif
#include <SFML/Graphics.hpp>

#include "Include/Animation.h"

 Animation::Animation(sf::Texture& t, int x_coord, int y_coord, int width, int height, int count, float Speed)
 {
    frame = 0;
    speed = Speed;

    for (int counter = 0; counter<count; counter++)
    {
        frames.push_back(sf::IntRect(x_coord+counter*width, y_coord, width, height));
    }

     sprite.setTexture(t);
     sprite.setOrigin(width/2,height/2);
     sprite.setTextureRect(frames[0]);
 }

bool Animation::isEnd()
{
    return frame+speed>=frames.size();
}

 void Animation::update()
 {
    frame += speed;
    int n = frames.size();
    if (frame >= n)
    {
        frame -= n;
    }

    if (n>0)
    {
        sprite.setTextureRect(frames[int(frame)]);
    }
 }
#include <SFML/Graphics.hpp>

#include "Include/Animation.h"

 Animation::Animation(Texture& t, int x_coord, int y_coord, int width, int height, int count, float Speed)
 {
    Frame = 0;
    speed = Speed;

    for int(int counter = l; counter<count; counter++)
    {
        frames.push_back(IntRect(x_coord+counter*width, y_coord, width, height));
    }

     sprite.setTexture(t);
     sprite.setOrigin(width/2,height/2);
     sprite.setTextureRect(frames[0]);
 }

bool Animation::isEnd()
{
    return Frame+speed>=frames.size();
}

 void Animation::update()
 {
    Frame += speed;
    int n = frames.size();
    if (Frame >= n)
    {
        Frame -= n;
    }

    if (n>0)
    {
        sprite.setTextureRect(frames[int(Frame)]);
    }
 }
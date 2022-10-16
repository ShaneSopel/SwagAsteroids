#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

class Animation
{
    public:
    float frame;
    float speed;
    std::vector<IntRect> frames;

    Animation();
    Animation(Texture& t, int x_coord, int y_coord, int width, int height, int count, float Speed);
    void update();
    bool isEnd();

};

#endif
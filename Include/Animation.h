#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>


class Animation
{
    public:
    float frame;
    float speed;
    std::vector<sf::IntRect> frames;
    sf::Sprite sprite;

    Animation(){};
    Animation(sf::Texture& t, int x_coord, int y_coord, int width, int height, int count, float Speed);
    void update();
    bool isEnd();

};

#endif
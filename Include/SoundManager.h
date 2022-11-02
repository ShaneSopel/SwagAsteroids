#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <list>
#include <SFML/Audio.hpp>

class SoundManager
{
    private:

    sf::SoundBuffer sblaser;
    sf::SoundBuffer sbExplosion;
    sf::Sound Lasersound;
    sf::Sound Explosionsound1; 

    public:

    void LoadSound();
    void TypeSound();
    void getLaser();
    void getExplosion();

     
};

#endif
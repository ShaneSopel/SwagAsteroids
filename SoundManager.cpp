#include "Include/SoundManager.h"

void SoundManager::LoadSound() 
{
    sblaser.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Sounds/Laser1.wav");
    sbExplosion.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Sounds/Explosion-Hard.wav");
    Lasersound.setBuffer(sblaser);
    Explosionsound1.setBuffer(sbExplosion);

}

void SoundManager::getLaser()
{
    return Lasersound.play();
}

void SoundManager::getExplosion()
{
    return Explosionsound1.play();
}

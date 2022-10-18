
#ifndef SPACE_CONSTANTS_H
#define SPACE_CONSTANTS_H

#include <chrono>

namespace SpaceConstants
{
    
constexpr unsigned short MAP_WIDTH1 = 800;
constexpr unsigned short MAP_HEIGHT1 = 600;
const float DEGTORAD = 0.017453f;


//This is in frames.
constexpr unsigned short TIMER_INITIAL_DURATION = 4096;
//After the player passes the level, we reduce the duration of the timer by this amount.
constexpr unsigned short TIMER_REDUCTION = 512;

constexpr std::chrono::microseconds FRAME_DURATION(16667);

}

#endif
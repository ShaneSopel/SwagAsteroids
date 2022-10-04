
#ifndef SPACE_CONSTANTS_H
#define SPACE_CONSTANTS_H

#include <chrono>

namespace SpaceConstants
{
    
constexpr unsigned char CELL_SIZE = 41;
constexpr unsigned char FAST_SPEED = 3;
constexpr unsigned char FONT_HEIGHT = 16;
constexpr unsigned char SHIP_ANIMATION_SPEED = 8;
constexpr unsigned char MAP_WIDTH = 20;
constexpr unsigned char MAP_HEIGHT = 20;
constexpr unsigned char NORMAL_SPEED = 2;
constexpr unsigned char SCREEN_RESIZE = 2;
constexpr unsigned char SLOW_SPEED = 1;
constexpr unsigned char TOTAL_LEVELS = 8;

//This is in frames.
constexpr unsigned short TIMER_INITIAL_DURATION = 4096;
//After the player passes the level, we reduce the duration of the timer by this amount.
constexpr unsigned short TIMER_REDUCTION = 512;

constexpr std::chrono::microseconds FRAME_DURATION(16667);

}

#endif

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Include/DrawMap.h"
#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"

using namespace SpaceConstants;

int main()
{
   	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, SCREEN_RESIZE * (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)), "SpaceShip", sf::Style::Close);

   window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    std::chrono::microseconds lag(0);

	std::chrono::steady_clock::time_point previous_time;

    previous_time = std::chrono::steady_clock::now();

    SpaceShip spaceship;

    while (window.isOpen())
    {

        std::chrono::microseconds delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time);

		lag += delta_time;

        sf::Event event;

        previous_time += delta_time;

        while (FRAME_DURATION <= lag)
        {
            lag -= FRAME_DURATION;

            while (window.pollEvent(event) == 1)
            {
                if (event.type == sf::Event::Closed)
                window.close();
            }

            spaceship.update();

                if (FRAME_DURATION > lag)
                {
                    window.clear();
                    
                    draw_map(window);

                    if (spaceship.get_Destroyed() == 0)
                    {
                        spaceship.draw(window);
                    }

                     spaceship.update();

                    window.display();

                }

        }
        
    }
    
}
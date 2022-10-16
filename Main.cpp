
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "Include/Asteroids.h"
#include "Include/Animation.h"
#include "Include/DrawMap.h"
#include "Include/Entity.h"
#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"

using namespace SpaceConstants;

int main()
{
    unsigned char level = 0;

   	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, SCREEN_RESIZE * (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)), "SpaceShip", sf::Style::Close);

    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    std::chrono::microseconds lag(0);

	std::chrono::steady_clock::time_point previous_time;

    previous_time = std::chrono::steady_clock::now();

    SpaceShip spaceship;
    sf::Texture t1;
    t1.loadFromFile("/home/shanes/c++/SwagAsteroids/Resources/Images/Asteroids2.png");
    Animation sRock(t1, 0,0,64,64, 16, 0.2);

    std::list<Entity*> entities;

    for(int i=0;i<15;i++)
    {
      Asteroids *a = new Asteroids();
      a->settings(sRock, rand()%MAP_WIDTH1, rand()%MAP_HEIGHT1, rand()%360, 25);
      entities.push_back(a);
    }

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

                    if (rand()%150==0)
                    {
                        Asteroids *a = new Asteroids();
                        a->settings(sRock, 0,rand()%MAP_HEIGHT1, rand()%360, 25);
                        entities.push_back(a);
                    }

                    spaceship.update();
                    for(auto i:entities) i->draw(window);
                    window.display();

                }

        }
        
    }
    
}
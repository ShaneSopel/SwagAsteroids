#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Include/Asteroids.h"
#include "Include/SpaceShip.h"
#include "Include/AsteroidsManager.h"
#include "Include/SpaceConstants.h"

using namespace SpaceConstants;

AsteroidsManager::AsteroidsManager(unsigned char i_level)
{
	generate_level(i_level);
}

void AsteroidsManager::draw(sf::RenderWindow& i_window)
{
	for (Asteroids& asteroid : asteroidsManager)
	{
		asteroid.draw(i_window);
	}
}

void AsteroidsManager::generate_level(unsigned char i_level)
{
	asteroidsManager.clear();

	switch (i_level)
	{
		case 0:
		{
			asteroidsManager.push_back(Asteroids(1, 0));
			asteroidsManager.push_back(Asteroids(9, 0));

			asteroidsManager.push_back(Asteroids(7, 1));
			asteroidsManager.push_back(Asteroids(11, 1));

			asteroidsManager.push_back(Asteroids(8, 3));
			asteroidsManager.push_back(Asteroids(10, 2));

			asteroidsManager.push_back(Asteroids(2, 3));

			asteroidsManager.push_back(Asteroids(0, 4));
			asteroidsManager.push_back(Asteroids(6, 4));
			asteroidsManager.push_back(Asteroids(13, 4));

			asteroidsManager.push_back(Asteroids(0, 5));
			asteroidsManager.push_back(Asteroids(7, 5));
			asteroidsManager.push_back(Asteroids(14, 5));

			break;
		}
		case 1:
		{
			asteroidsManager.push_back(Asteroids(1, 0));
			asteroidsManager.push_back(Asteroids(7, 0));
			asteroidsManager.push_back(Asteroids(13, 0));

			asteroidsManager.push_back(Asteroids(4, 1));
			asteroidsManager.push_back(Asteroids(10, 1));
			asteroidsManager.push_back(Asteroids(14, 1));

			asteroidsManager.push_back(Asteroids(9, 2));
			asteroidsManager.push_back(Asteroids(14, 2));

			asteroidsManager.push_back(Asteroids(5, 3));
			asteroidsManager.push_back(Asteroids(7, 3));

			asteroidsManager.push_back(Asteroids(2, 4));
			asteroidsManager.push_back(Asteroids(10, 4));
			asteroidsManager.push_back(Asteroids(15, 4));
			asteroidsManager.push_back(Asteroids(21, 4));

			asteroidsManager.push_back(Asteroids(0, 5));
			asteroidsManager.push_back(Asteroids(4, 5));
			asteroidsManager.push_back(Asteroids(11, 5));
			asteroidsManager.push_back(Asteroids(18, 5));

			break;
		}
		case 2:
		{
			asteroidsManager.push_back(Asteroids(1, 0));
			asteroidsManager.push_back(Asteroids(5, 0));
			asteroidsManager.push_back(Asteroids(12, 0));
			asteroidsManager.push_back(Asteroids(19, 0));

			asteroidsManager.push_back(Asteroids(4, 1));
			asteroidsManager.push_back(Asteroids(9, 1));
			asteroidsManager.push_back(Asteroids(18, 1));

			asteroidsManager.push_back(Asteroids(2, 2));
			asteroidsManager.push_back(Asteroids(10, 2));
			asteroidsManager.push_back(Asteroids(18, 2));

			asteroidsManager.push_back(Asteroids(4, 3));

			asteroidsManager.push_back(Asteroids(0, 4));
			asteroidsManager.push_back(Asteroids(9, 4));
			asteroidsManager.push_back(Asteroids(13, 4));
			asteroidsManager.push_back(Asteroids(19, 4));

			asteroidsManager.push_back(Asteroids(2, 5));
			asteroidsManager.push_back(Asteroids(6, 5));
			asteroidsManager.push_back(Asteroids(15, 5));
			asteroidsManager.push_back(Asteroids(22, 5));

			break;
		}
		case 3:
		{
			asteroidsManager.push_back(Asteroids(3, 0));
			asteroidsManager.push_back(Asteroids(10, 0));
			asteroidsManager.push_back(Asteroids(16, 0));
			asteroidsManager.push_back(Asteroids(21, 0));

			asteroidsManager.push_back(Asteroids(2, 1));
			asteroidsManager.push_back(Asteroids(7, 1));
			asteroidsManager.push_back(Asteroids(15, 1));

			asteroidsManager.push_back(Asteroids(1, 2));
			asteroidsManager.push_back(Asteroids(5, 2));

			asteroidsManager.push_back(Asteroids(4, 3));
			asteroidsManager.push_back(Asteroids(13, 3));
			asteroidsManager.push_back(Asteroids(10, 3));

			asteroidsManager.push_back(Asteroids(3, 4));
			asteroidsManager.push_back(Asteroids(6, 4));
			asteroidsManager.push_back(Asteroids(13, 4));
			asteroidsManager.push_back(Asteroids(20, 4));

			asteroidsManager.push_back(Asteroids(1, 5));
			asteroidsManager.push_back(Asteroids(4, 5));
			asteroidsManager.push_back(Asteroids(10, 5));
			asteroidsManager.push_back(Asteroids(16, 5));

			break;
		}
		case 4:
		{
			asteroidsManager.push_back(Asteroids(0, 0));
			asteroidsManager.push_back(Asteroids(6, 0));
			asteroidsManager.push_back(Asteroids(11, 0));
			asteroidsManager.push_back(Asteroids(21, 0));

			asteroidsManager.push_back(Asteroids(2, 1));
			asteroidsManager.push_back(Asteroids(7, 1));
			asteroidsManager.push_back(Asteroids(16, 1));
			asteroidsManager.push_back(Asteroids(20, 1));

			asteroidsManager.push_back(Asteroids(1, 2));
			asteroidsManager.push_back(Asteroids(9, 2));
			asteroidsManager.push_back(Asteroids(15, 2));

			asteroidsManager.push_back(Asteroids(7, 3));
			asteroidsManager.push_back(Asteroids(13, 3));

			asteroidsManager.push_back(Asteroids(1, 4));
			asteroidsManager.push_back(Asteroids(8, 4));
			asteroidsManager.push_back(Asteroids(12, 4));
			asteroidsManager.push_back(Asteroids(18, 4));

			asteroidsManager.push_back(Asteroids(1, 5));
			asteroidsManager.push_back(Asteroids(8, 5));
			asteroidsManager.push_back(Asteroids(16, 5));
			asteroidsManager.push_back(Asteroids(21, 5));

			break;
		}
		case 5:
		{
			asteroidsManager.push_back(Asteroids(0, 0));
			asteroidsManager.push_back(Asteroids(4, 0));
			asteroidsManager.push_back(Asteroids(10, 0));
			asteroidsManager.push_back(Asteroids(15, 0));

			asteroidsManager.push_back(Asteroids(1, 1));
			asteroidsManager.push_back(Asteroids(6, 1));
			asteroidsManager.push_back(Asteroids(14, 1));
			asteroidsManager.push_back(Asteroids(18, 1));

			asteroidsManager.push_back(Asteroids(0, 2));
			asteroidsManager.push_back(Asteroids(6, 2));

			asteroidsManager.push_back(Asteroids(7, 3));
			asteroidsManager.push_back(Asteroids(12, 3));
			asteroidsManager.push_back(Asteroids(15, 3));

			asteroidsManager.push_back(Asteroids(0, 4));
			asteroidsManager.push_back(Asteroids(9, 4));
			asteroidsManager.push_back(Asteroids(13, 4));
			asteroidsManager.push_back(Asteroids(20, 4));

			asteroidsManager.push_back(Asteroids(0, 5));
			asteroidsManager.push_back(Asteroids(7, 5));
			asteroidsManager.push_back(Asteroids(15, 5));
			asteroidsManager.push_back(Asteroids(20, 5));

			break;
		}
		case 6:
		{
			asteroidsManager.push_back(Asteroids(0, 0));
			asteroidsManager.push_back(Asteroids(3, 0));
			asteroidsManager.push_back(Asteroids(8, 0));
			asteroidsManager.push_back(Asteroids(14, 0));

			asteroidsManager.push_back(Asteroids(0, 1));
			asteroidsManager.push_back(Asteroids(7, 1));
			asteroidsManager.push_back(Asteroids(15, 1));
			asteroidsManager.push_back(Asteroids(20, 1));

			asteroidsManager.push_back(Asteroids(1, 2));
			asteroidsManager.push_back(Asteroids(8, 2));

			asteroidsManager.push_back(Asteroids(0, 3));
			asteroidsManager.push_back(Asteroids(10, 3));
			asteroidsManager.push_back(Asteroids(19, 3));

			asteroidsManager.push_back(Asteroids(0, 4));
			asteroidsManager.push_back(Asteroids(7, 4));
			asteroidsManager.push_back(Asteroids(12, 4));
			asteroidsManager.push_back(Asteroids(19, 4));
			asteroidsManager.push_back(Asteroids(21, 4));

			asteroidsManager.push_back(Asteroids(0, 5));
			asteroidsManager.push_back(Asteroids(5, 5));
			asteroidsManager.push_back(Asteroids(16, 5));
			asteroidsManager.push_back(Asteroids(21, 5));

			break;
		}
		case 7:
		{
			asteroidsManager.push_back(Asteroids(1, 0));
			asteroidsManager.push_back(Asteroids(5, 0));
			asteroidsManager.push_back(Asteroids(8, 0));
			asteroidsManager.push_back(Asteroids(14, 0));
			asteroidsManager.push_back(Asteroids(18, 0));

			asteroidsManager.push_back(Asteroids(0, 1));
			asteroidsManager.push_back(Asteroids(7, 1));
			asteroidsManager.push_back(Asteroids(15, 1));
			asteroidsManager.push_back(Asteroids(20, 1));

			asteroidsManager.push_back(Asteroids(1, 2));
			asteroidsManager.push_back(Asteroids(8, 2));
			asteroidsManager.push_back(Asteroids(15, 2));

			asteroidsManager.push_back(Asteroids(0, 3));
			asteroidsManager.push_back(Asteroids(10, 3));
			asteroidsManager.push_back(Asteroids(19, 3));

			asteroidsManager.push_back(Asteroids(1, 4));
			asteroidsManager.push_back(Asteroids(7, 4));
			asteroidsManager.push_back(Asteroids(11, 4));
			asteroidsManager.push_back(Asteroids(18, 4));
			asteroidsManager.push_back(Asteroids(22, 4));

			asteroidsManager.push_back(Asteroids(0, 5));
			asteroidsManager.push_back(Asteroids(4, 5));
			asteroidsManager.push_back(Asteroids(9, 5));
			asteroidsManager.push_back(Asteroids(16, 5));
			asteroidsManager.push_back(Asteroids(20, 5));
		}
	}
}

void AsteroidsManager::update(SpaceShip& i_spaceship)
{
	for (Asteroids& Asteroid : asteroidsManager)
	{
		Asteroid.update();
	}

	if (0 == i_spaceship.get_Destroyed())
	{
		for (Asteroids& Asteroid : asteroidsManager)
		{
			if (1 == Asteroid.get_rect().intersects(i_spaceship.get_rect()))
			{
				i_spaceship.set_Destroyed();
			}
		}
	}
}

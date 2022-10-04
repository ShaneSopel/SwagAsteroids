#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"

using namespace SpaceConstants;

SpaceShip::SpaceShip()
{
    reset();
}

bool SpaceShip::get_Destroyed() const
{
    return destroyed;
}

bool SpaceShip::update_space(std::array<bool, 5>& i_space)
{
		if (CELL_SIZE >= y_dir)
	{
		if (floor(0.75f * CELL_SIZE) <= x_dir % (3 * CELL_SIZE) && floor(2.25f * CELL_SIZE) >= x_dir % (3 * CELL_SIZE))
		{
			unsigned char space_spot = static_cast<unsigned char>(floor(x_dir / static_cast<float>(3 * CELL_SIZE)));

			if (0 == i_space[space_spot])
			{
				i_space[space_spot] = 1;

				return 1;
			}
			else
			{
				set_Destroyed();
			}
		}
		else
		{
			set_Destroyed();
		}
	}

	return 0;

}

void SpaceShip::draw(sf::RenderWindow& i_window)
{
//	if (destroyed == 0)
//	{
		texture.loadFromFile("/home/shane/c++/SpaceGameC++/Resources/Images/starship1.png");
//	}
	//else
	//{
	//	texture.loadFromFile("/home/shane/c++/SpaceGameC++/Resources/Images/starship.png");
//	}

	sprite.setPosition(x_dir, y_dir);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(CELL_SIZE * current_frame, CELL_SIZE * direction, CELL_SIZE, CELL_SIZE));

	i_window.draw(sprite);
}

void SpaceShip::move(char i_value)
{
	x_dir = std::clamp(i_value + x_dir, 0, CELL_SIZE * (MAP_WIDTH - 1));
}

void SpaceShip::reset()
{
    destroyed = 0;

	x_dir = static_cast<short>(CELL_SIZE * floor(0.5f * MAP_WIDTH));

	animation_timer = 0;
	current_frame = 1;
	direction = 1;

	y_dir = CELL_SIZE * (MAP_HEIGHT - 1);

	control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void SpaceShip::set_Destroyed()
{
	if (0 == destroyed)
	{
		destroyed = 1;

		animation_timer = 0;
		current_frame = 0;
	}

}

void SpaceShip::update()
{
	if (destroyed == 0)
	{
		bool moved = 0;
		if (control_keys[0] == 0 && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moved = 1;

			x_dir = std::min(CELL_SIZE + x_dir, CELL_SIZE * (MAP_WIDTH -1));

			direction = 0;
		}
		else if (control_keys[1] == 0 && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			moved = 1;

			y_dir = std::max(y_dir - CELL_SIZE, 0);

			direction = 1;
		}
		else if (control_keys[2] == 0 && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moved = 1;

			x_dir = std::max(x_dir - CELL_SIZE, 0);

			direction = 2;
		}
		else if (control_keys[3] == 0 && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			moved = 1;

			y_dir = std::min(CELL_SIZE + y_dir , CELL_SIZE * (MAP_HEIGHT-1));

			direction = 3;
		}
		
		control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

		if (moved == 1)
		{
			animation_timer = SHIP_ANIMATION_SPEED;
			current_frame = 0;
		}

		if (animation_timer == 0)
		{
			current_frame = 1;
		}
		else
		{
			animation_timer --;
		}

	}

	else if(y_dir < CELL_SIZE * floor(0.5f * MAP_HEIGHT))
	{
		if(animation_timer == 0)
		{
			animation_timer = SHIP_ANIMATION_SPEED;
			current_frame = std::min(3, 1 + current_frame);
		}
		else
		{
			animation_timer--;
		}

	}

}

sf::IntRect SpaceShip::get_rect() const
{
	return sf::IntRect(x_dir, y_dir, CELL_SIZE, CELL_SIZE);
}

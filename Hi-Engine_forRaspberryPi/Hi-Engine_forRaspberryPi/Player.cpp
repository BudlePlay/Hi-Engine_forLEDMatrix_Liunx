#include "Player.h"
#include "LEDMatrix.h"

Player::Player(const FPosition& p, const std::string& name, const std::string& shape, const Area& Area,
               const std::string& direction, const std::string& Type): Object(p, name, shape, Area, direction, Type)
{
	is_input_ = false;
}

void Player::Work()
{
	int data = LEDMatrix::get_joy();

	if (data != -1)
	{
		player_input_ = (PLAYER_INPUT)data;
		control();
	}
}

void Player::OnCollision(Object* other)
{
}

void Player::control()
{
	
	if (player_input_ == UP)
	{
		Translate({ 0,-1 });
	}
	else if (player_input_ == DOWN)
	{
		Translate({ 0,1 });
	}
	else if (player_input_ == LEFT)
	{
		Translate({ -1,0 });
	}
	else if (player_input_ == RIGHT)
	{
		Translate({ 1,0 });
	}
}

void Player::move()
{
}

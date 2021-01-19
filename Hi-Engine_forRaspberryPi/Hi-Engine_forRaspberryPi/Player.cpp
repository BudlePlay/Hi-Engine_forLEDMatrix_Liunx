#include "Player.h"
#include "IORaspberryPi.h"

Player::Player(const FPosition& p, const std::string& name, const std::string& shape, const Area& Area,
               const std::string& direction, const std::string& Type): Object(p, name, shape, Area, direction, Type)
{
	is_input_ = false;

	prev_position_ = p;

}

void Player::Work()
{
	int data = IORaspberryPi::get_joy();

	std::cout << IORaspberryPi::get_btn(0) << std::endl;

	if (delaycnt > 10)
	{
		if (data != -1)
		{
			player_input_ = (PLAYER_INPUT)data;
			control();
		}
		delaycnt = 0;
	}
	delaycnt++;
}

void Player::OnCollision(Object* other)
{
	position = prev_position_;
}

void Player::control()
{
	prev_position_ = position;
	
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

void Player::jump(int i)
{
	return;
}

#pragma once

#include "Object.h"

enum PLAYER_INPUT
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};
class Player : public Object
{
public:
	Player(const FPosition& p, const std::string& name, const std::string& shape, const Area& Area,
	       const std::string& direction, const std::string& Type);

	void Work() override;
	
	void OnCollision(Object* other) override;

private:
	bool is_input_;
	PLAYER_INPUT player_input_;
	void control();
	void move();
};
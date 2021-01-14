#pragma once

#include "Object.h"
#include "Tools.h"

class Player : public Object
{
public:
	Player(const FPosition& p, const std::string& name, const std::string& shape, const Area& Area,
	       const std::string& direction, const std::string& Type);

	void Work() override;
	
	void OnCollision(Object* other) override;

private:

	int delaycnt = 0;
	
	bool is_input_;
	PLAYER_INPUT player_input_;
	FPosition prev_position_{0,0};
	void control();
	void move();
};
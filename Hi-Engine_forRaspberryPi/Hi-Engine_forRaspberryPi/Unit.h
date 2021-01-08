#pragma once


struct Position
{
	int x;
	int y;
};

struct FPosition
{
	float x;
	float y;
	FPosition(float x_, float y_) : x(x_), y(y_) {}
};

struct Area
{
	int width;
	int height;

	Area(int width_, int height_) : width(width_), height(height_){}
};
class PositionTools
{
public:
	static Position FPtoIP(FPosition fp);

	static bool IsEqual(FPosition m, FPosition o);
};
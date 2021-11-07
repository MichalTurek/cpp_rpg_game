#pragma once
const int max_level = 10;
enum class Direction
{
	left = 0,
	right,
	up,
	down
};



struct coordinates
{
	int x, y;
	coordinates(int x, int y) :
		x(x),
		y(y)
	{
	}
	bool operator==(const coordinates c)
	{
		return (this->x == c.x && this->y == c.y);
	}
};

const double ORGANISM_SPAWN_CHANCE = 0.1;

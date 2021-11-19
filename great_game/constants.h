#pragma once

const int max_level = 10;
class Organism;
using organism_iterator = std::vector<unique_ptr<Organism>>::iterator;

enum class Direction
{
	left = 0,
	right,
	up,
	down,
	undef,
};
enum class Combat_status
{
	no_result_yet=0,
	attcker_won,
	defender_won
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
constexpr int KEY_UP = 72;
constexpr int KEY_DOWN = 80;
constexpr int KEY_LEFT = 75;
constexpr int KEY_RIGHT = 77;
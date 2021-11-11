#pragma once
const int max_level = 10;
enum class Direction
{
	left = 0,
	right,
	up,
	down,
	undef,
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

struct organism_combat_modifiers
{
	double  dmg_absorption, dodge_chance;
	organism_combat_modifiers(double dodge_chance,double dmg_absorption)
		:
		dmg_absorption(dmg_absorption),
		dodge_chance(dodge_chance)
	{
	}
};
const double ORGANISM_SPAWN_CHANCE = 0.1;
constexpr int KEY_UP = 72;
constexpr int KEY_DOWN = 80;
constexpr int KEY_LEFT = 75;
constexpr int KEY_RIGHT = 77;
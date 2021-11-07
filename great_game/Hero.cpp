#include "pch.h"
#include "Hero.h"
#include "conio.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Hero::Hero(coordinates organism_pos, World* act_world)
	:
	Organism(organism_pos, act_world)
{
	this->strength = 5;
	this->dexterity = 5;
	this->inteligence = 5;
	this->armor = 4;
	this->damage = 2;
	this->health = 5 + (strength*5);
	this->attack_speed = 4;
}

void Hero::draw_organism()
{
	cout << "O";
}

void Hero::action()
{
	coordinates new_pos = organism_coordinates;
	int z;
	switch((z = _getch()))
	{
	case KEY_UP:
		if (new_pos.y > 0)
		{
			new_pos.y--;
		}
		break;

	case KEY_DOWN:
		if (new_pos.y < world->get_y_size() - 1)
		{
			new_pos.y++;
		}
		break;

	case KEY_LEFT:
		if (new_pos.x > 0)
		{
			new_pos.x--;
		}
		break;

	case KEY_RIGHT:
		if (new_pos.x < world->get_x_size() - 1)
		{
			new_pos.x++;
		}
		break;

	default:
		break;
	}

	this->set_coordinates(new_pos);
}
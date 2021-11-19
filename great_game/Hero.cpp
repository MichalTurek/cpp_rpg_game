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
	this->max_health = 5 + (strength*5);
	this->health = max_health;
	this->attack_speed = 6;
	this->level = 1;
	this->dodge = 2;
}

void Hero::draw_organism()
{
	cout << "O";
}

void Hero::action()
{
	coordinates new_pos = organism_coordinates;
	Direction player_choice=Direction::undef;
	_getch();
	while(player_choice == Direction::undef)
	{
		player_choice = static_cast<Direction>(_getch());
		if (new_pos.y > 0 &&static_cast<int>(player_choice) == KEY_UP)  new_pos.y--;
		else if (new_pos.y < world->get_y_size() - 1 && static_cast<int>(player_choice) == KEY_DOWN)  new_pos.y++;
		else if (new_pos.x > 0 && static_cast<int>(player_choice) == KEY_LEFT)  new_pos.x--;
		else if (new_pos.x < world->get_x_size() - 1 && static_cast<int>(player_choice) == KEY_RIGHT)  new_pos.x++;
	}
	this->set_coordinates(new_pos);
	world->draw_world();
}
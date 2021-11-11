#include "pch.h"
#include "Sheep.h"
Sheep::Sheep( coordinates organism_pos, World* act_world)
	:
	Organism(organism_pos, act_world)
{
	this->armor = 0;
	this->damage = 2;
	this->health = 10;
	this->attack_speed = 4;
	this->level = 1;
}
void Sheep::draw_organism()
{
	cout << "s";

}
#pragma once
#include "pch.h"
#include "World.h"
using organism_iterator = std::vector<unique_ptr<Organism>>::iterator;
struct organism_combat_modifiers;
class Organism
{
protected:

	int max_health, health, damage, armor, dodge, level;
	double attack_speed;
	int  damage_absorption;
	coordinates organism_coordinates;
	World* world;
public:

	Organism(coordinates organism_coordinates, World* world);

	virtual void action();
	//finds new position for organism
	coordinates find_new_position();
	//fight functions 
	void collision(organism_iterator attacker_iterator);
	double calc_dmg_modifier(organism_iterator  organism_in_fight_ptr) const;
	double calc_hit_chance(organism_iterator  organism_in_fight_ptr) const;
	void deal_damage_to(organism_iterator  attacked_organism, organism_combat_modifiers attacker_modifiers);
	virtual void after_winning_fight_against(organism_iterator beaten_organism);
	virtual void draw_organism() = 0;
	//getters
	coordinates get_coordinates() const { return organism_coordinates; }
	int get_health()const { return health; }
	int get_damage()const { return damage; }
	int get_attack_speed()const { return attack_speed; }
	int get_armor()const { return armor; }
	int get_level()const { return level; }
	//setters
	void set_coordinates(coordinates new_coord) { organism_coordinates = new_coord; }
	void set_health(int new_health) { health = new_health; }
	void set_damage(int new_damage) { damage = new_damage; }
	void set_armor(int new_armor) { armor = new_armor; }

};
//move it to new .h file 

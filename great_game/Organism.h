#pragma once
#include "pch.h"
#include "World.h"
class Organism
{
protected:
	coordinates organism_coordinates;
	int max_health,health, damage, armor,attack_speed,dodge, level;
	int  damage_absorption;

	World* world;
public:
	virtual void action();
	//finds new position for organism
	coordinates find_new_position();
	void collision();//todo later
	double calc_dmg_modifier(unique_ptr<Organism> organism_in_fight_ptr) const;
	double calc_dodge_chance(unique_ptr<Organism> organism_in_fight_ptr) const;
	void deal_damage_to(unique_ptr<Organism> attacked_organism, int damage_modifier, int attacked_organism_dodge_chance);
	
	Organism(coordinates organism_coordinates, World* world);
	virtual void draw_organism()=0;
	//getters
	coordinates get_coordinates() const { return organism_coordinates; }
	int get_health()const { return health; }
	int get_damage()const { return damage; }
	int get_attack_speed()const { return attack_speed; }
	int get_armor()const { return armor; }
	int get_level()const { return level; }
	//setters
	void set_coordinates(coordinates new_coord)  {  organism_coordinates = new_coord; }
	void set_health(int new_health) { health = new_health; }
	void set_damage(int new_damage) { damage = new_damage; }
	void set_armor(int new_armor) { armor = new_armor; }

};


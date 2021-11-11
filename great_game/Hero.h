#pragma once
#include "pch.h"
class Hero : public Organism
{
	
	//base hero stats
	int strength,dexterity,inteligence;
	
public:
	Hero(coordinates organism_pos, World* world);

	int get_strength() const { return strength; }
	int get_dexterity() const { return dexterity; }
	int get_inteligence() const { return strength; }

	void action() override;

	void draw_organism() override;
	
	//virtual void level_up()=0;
};


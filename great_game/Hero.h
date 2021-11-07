#pragma once
#include "pch.h"
class Hero : public Organism
{
	//base hero stats
	int strength,dexterity,inteligence;
	
	int get_strength() const { return strength; }
	int get_dexterity() const { return dexterity; }
	int get_inteligence() const { return strength; }


	void action() {};
	
	virtual void level_up()=0;
};


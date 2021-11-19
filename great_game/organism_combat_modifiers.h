#pragma once
#include "Organism.h"
struct organism_combat_modifiers
{
	double  dmg_absorption, dodge_chance;
	organism_combat_modifiers(organism_iterator attacking_organism, organism_iterator defending_organism)
	{
		dmg_absorption = ((**attacking_organism).calc_dmg_modifier(defending_organism));
		dodge_chance = ((**attacking_organism).calc_hit_chance(defending_organism));
	}
};
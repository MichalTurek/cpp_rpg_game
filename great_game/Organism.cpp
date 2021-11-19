#include "pch.h"
#include "Organism.h"
#include "organism_combat_modifiers.h"
Organism::Organism(coordinates organism_coordinates, World* world)
	:
	organism_coordinates(organism_coordinates),
	world(world)
{
}
void Organism::action()
{
	//issues with collision to fix later
	coordinates new_pos = this->find_new_position();
	if (new_pos == organism_coordinates) return;
	auto& organism_vector = world->get_vector();
	//checks if new pos of organism is already taken by other organism
	auto attacked_organism = find_if(begin(organism_vector), end(organism_vector), [&new_pos, this](const unique_ptr<Organism>& attacked_organism)
		{
			return new_pos == attacked_organism->get_coordinates() && this != attacked_organism.get();
		});
	//if organism not found	
	if (attacked_organism == end(organism_vector))
	{
		this->set_coordinates(new_pos);
	}
	//tofixlater: if for organism name
	else if((*attacked_organism)->get_attack_speed() != this->get_attack_speed())
	{
		this->collision(attacked_organism);
	}

	return;
	//collision to add later
}
coordinates Organism::find_new_position()
{
	Direction direction = static_cast<Direction>(rand() % 4);
	coordinates new_pos = organism_coordinates;
	if (direction == Direction::left && new_pos.x != 0)
	{
		new_pos.x--;
	}
	if (direction == Direction::right && new_pos.x != world->get_x_size() - 1)
	{
		new_pos.x++;
	}
	if (direction == Direction::up && new_pos.y != 0)
	{
		new_pos.y--;
	}
	if (direction == Direction::down && new_pos.y != world->get_y_size() - 1)
	{
		new_pos.y++;
	}
	return new_pos;
}
double Organism::calc_dmg_modifier(organism_iterator  organism_in_fight_ptr) const
{
	double dmg_modifier = static_cast<double>(this->damage) - (*organism_in_fight_ptr)->get_armor();
	dmg_modifier /= this->damage;
	return dmg_modifier > 0.2 ? dmg_modifier : 0.2;
}
double Organism::calc_hit_chance(organism_iterator  organism_in_fight_ptr) const
{
	return static_cast<double>(this->dodge) / (*organism_in_fight_ptr)->get_level();
}
void Organism::deal_damage_to(organism_iterator  attacked_organism, organism_combat_modifiers attacker_modifiers)
{
	if (rand() % 10 / 100.0 < attacker_modifiers.dodge_chance ) return;
	(*attacked_organism)->set_health((*attacked_organism)->get_health() -(1 -attacker_modifiers.dmg_absorption) * damage);
	return;
}
void Organism::collision(organism_iterator attacker_iterator)
{
	auto& organism_vector = world->get_vector();
	auto defender_iterator = find_if(begin(organism_vector), end(organism_vector), [this](const unique_ptr<Organism>& candidate_organism)
		{
			return this->get_coordinates() == candidate_organism->get_coordinates() && this == candidate_organism.get();
		});
	int attack_full_charge_val;
	double attacker_atk_speed = (*attacker_iterator)->get_attack_speed(); 
	double defender_atk_speed = (*defender_iterator)->get_attack_speed();
	(attacker_atk_speed < defender_atk_speed) ? attack_full_charge_val = defender_atk_speed : attack_full_charge_val = attacker_atk_speed;

	double attacker_attack_charge = 0, defender_charge = 0;
	organism_combat_modifiers attacker_modifiers(attacker_iterator, defender_iterator);
	organism_combat_modifiers defender_modifiers(defender_iterator, attacker_iterator);
	Combat_status fight_result = Combat_status::no_result_yet;
	while (fight_result == Combat_status::no_result_yet)
	{
		defender_charge += defender_atk_speed;
		attacker_attack_charge += attacker_atk_speed;
		if (defender_charge - attack_full_charge_val >= 0)
		{
			defender_charge -= attack_full_charge_val;
			(*defender_iterator)->deal_damage_to(defender_iterator,attacker_modifiers);
		}
		if (attacker_attack_charge - attack_full_charge_val >= 0)
		{
			attacker_attack_charge -= attack_full_charge_val;
			this->deal_damage_to(attacker_iterator, defender_modifiers);
		}
		if ((*attacker_iterator)->get_health() < 0)
		{
			fight_result = Combat_status::defender_won;
			(*defender_iterator)->after_winning_fight_against(defender_iterator);
		}
		if ((*defender_iterator)->get_health() < 0)
		{
			fight_result = Combat_status::attcker_won;
			(*attacker_iterator)->after_winning_fight_against(defender_iterator);

		}
	}

}
void Organism::after_winning_fight_against(organism_iterator beaten_organism)
{
	this->set_health(this->max_health);
	
}
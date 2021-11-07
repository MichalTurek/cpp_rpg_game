#include "pch.h"
#include "Organism.h"
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
	else
	{
		/*cout << "napierdlaja sie x:" ;
		cout << new_pos.x << " , y: " << new_pos.y << endl;*/
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
double Organism::calc_dmg_modifier(unique_ptr<Organism> organism_in_fight_ptr) const
{
	double dmg_modifier = static_cast<double>(this->damage) - organism_in_fight_ptr->get_armor();
	dmg_modifier /= this->damage;
	return dmg_modifier > 0.2 ? dmg_modifier : 0.2;
}
double Organism::calc_dodge_chance(unique_ptr<Organism> organism_in_fight_ptr) const
{
	return static_cast<double>(this->dodge) / organism_in_fight_ptr->get_level();

}
void Organism::deal_damage_to(unique_ptr<Organism> attacked_organism, int damage_modifier, int attacked_organism_dodge_chance)
{
	if (rand() % 10 / 100.0 < attacked_organism_dodge_chance) return;
	else  attacked_organism->set_health(attacked_organism->get_health() - damage_modifier * damage);
	return;
}
void Organism::collision()
{
	//finding another organism
	auto& organism_vector = world->get_vector();
	auto attacked_organism_iterator = find_if(begin(organism_vector), end(organism_vector), [this](const unique_ptr<Organism>& candidate_organism)
		{
			return this->get_coordinates() == candidate_organism->get_coordinates() && this != candidate_organism.get();
		});

	//HERE I WANT TO CHECK IF THEY ARE OBJECTS OF THE SAME class
	int attack_charge;
	double organism_atk_speed = this->get_attack_speed();
	double attacked_organism_atk_speed = (*attacked_organism_iterator)->get_attack_speed();
	double organism_attack_charge = 0;
	double attacked_organism_charge = 0;

	(organism_atk_speed < attacked_organism_atk_speed) ? attack_charge = attacked_organism_atk_speed : attack_charge = organism_atk_speed;
	while (true)
	{
		attacked_organism_charge += attacked_organism_atk_speed;
		organism_attack_charge += organism_atk_speed;
	}

}
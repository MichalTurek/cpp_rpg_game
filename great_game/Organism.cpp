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
	auto& organism_vector  = world->get_vector();
	//checks if new pos of organism is already taken by other organism
	auto attacked_organism = find_if(begin(organism_vector), end(organism_vector), [&new_pos,this](const unique_ptr<Organism>& attacked_organism)
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
void Organism::collision()
{
	auto& organism_vector = world->get_vector();
	auto attacked_organism_iterator = find_if(begin(organism_vector), end(organism_vector), [this](const unique_ptr<Organism>& candidate_organism)
		{
			return this->get_coordinates() == candidate_organism->get_coordinates() && this != candidate_organism.get();
		});
	//TODO: CHECKING ORGANISMS TYPE
	//
	//
	//(**attacked_organism).set_health(0);

}
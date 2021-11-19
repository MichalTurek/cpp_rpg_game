#include "pch.h"
#include "World.h"
#include "Sheep.h"
#include "Hero.h"

World::World(int act_level) :
	organisms_vector(generate_organisms(act_level))
{
}

void World::make_turn()
{
	cout << "new turn" << endl;
	//sorting organisms by their vigor and also by age ( older organisms make move first)
	stable_sort(begin(organisms_vector), end(organisms_vector),
		[](const unique_ptr<Organism>& organism_1,const unique_ptr<Organism>& organism_2)
		{
			return organism_1->get_attack_speed() > organism_2->get_attack_speed(); 
		});
	for (auto& actual_organism : organisms_vector)
	{
		actual_organism->action();
		draw_world();
	}
}
vector<unique_ptr<Organism>>  World::generate_organisms(int act_level)
{
	vector<unique_ptr<Organism>> organism_list;
	//TODO RANDOM ORGANISM GENERATION
	this->x_size = rand() % 15+5 + act_level;
	this->y_size = rand() % 15+5 + act_level;
	
	for (int x = 0; x < this->get_x_size(); x++)
	{
		for (int y = 0; y < this->get_y_size(); y++)
		{
			if (static_cast<float>(rand() % 10) / 10 < ORGANISM_SPAWN_CHANCE)
			{
				coordinates new_organism_pos(x, y);
				organism_list.push_back(make_unique<Sheep>(new_organism_pos, this));
			}
		}
	}
	coordinates new_organism_pos(0, 0);
	organism_list.push_back(make_unique<Hero>(new_organism_pos, this));
	return organism_list;
}
void World::remove_organism(organism_iterator organism_to_delete)
{
	organisms_vector.erase(organism_to_delete);
}
void World::draw_world() const
{
	system("CLS");
	/*for (const unique_ptr<Organism>& organism : organisms_vector)
	{
		cout << organism->get_coordinates().x << " " << organism->get_coordinates().y << endl;
	}*/
	int x_size = this->get_x_size()+2;
	int y_size = this->get_y_size()+2;
	for (int y = 0; y < y_size; y++)
	{

		for (int x = 0; x < x_size; x++)
		{
			bool printed = false;
			if (x == 0 && y == 0)
			{
				cout << char(201);
				printed = true;
			}
			else if (x == x_size-1 && y == 0)
			{
				cout << char(187);
				printed = true;
			}
			else if (x == 0 && y == y_size-1)
			{
				cout << char(200);
				printed = true;
			}
			else if (x == x_size-1 && y == y_size-1)
			{
				cout << char(188);
				printed = true;
			}
			else if (x == 0 || x == x_size-1)
			{
				cout << char(186);
				printed = true;
			}
			else if (y == 0 || y == y_size-1)
			{
				cout << char(205);
				printed = true;
			}
			else for (const unique_ptr<Organism>& organism : organisms_vector)
			{
				if (organism->get_coordinates().x == x - 1 && organism->get_coordinates().y == y - 1)
				{
					organism->draw_organism();
					printed = true;
				}
			}
			if (printed == false) cout << " ";
		}

		cout << endl;

	}
	int i = 0;
}
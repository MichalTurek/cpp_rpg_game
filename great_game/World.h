#pragma once
#include "pch.h"

class Organism;
class World
{
private:
	vector<unique_ptr<Organism>> organisms_vector;
	int x_size, y_size;
public:
	World(int act_level);
	vector<unique_ptr<Organism>> generate_organisms(int act_level);
	int get_x_size()const { return x_size; }
	int get_y_size()const { return y_size; }
	vector<unique_ptr<Organism>>& get_vector(){ return organisms_vector; }
	vector<unique_ptr<Organism>>::const_iterator get_const_organism_iterator() const
	{
		vector<unique_ptr<Organism>>::const_iterator iter = std::cbegin(organisms_vector);
		return iter;
	}
	void make_turn();
	void draw_world() const;
	
};


#pragma once
class Sheep : public Organism
{
public:
	Sheep( coordinates organism_pos, World* world);
	//override virtual methods
	void draw_organism() override;
};


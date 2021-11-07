#pragma once
#include "pch.h"

class Game_status
{
	unique_ptr<World> actual_wolrd;
	unique_ptr<Organism> player;
	int level = 1;
	Game_status();
	void next_level();

};


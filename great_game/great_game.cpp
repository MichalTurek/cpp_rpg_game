#include "pch.h"
#include "Hero.h"
#include "Sheep.h"
int main()
{
	srand(time(NULL));
	World new_world(1);

	while (true)
	{
		new_world.make_turn();
		Sleep(1000);
	}
}


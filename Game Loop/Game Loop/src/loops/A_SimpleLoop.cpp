#include "A_SimpleLoop.h"

// Update & FPS dependent on machine
void Run_SimpleLoop(Game* game)
{

	while (game->IsRunning())
	{
		game->UpdateGame(TIME_UNIT(1));		// Update with an arbitraty constant amount.
		game->DisplayGame();				// Update & Display are called as fast as possible.
	}

}

/*

- Completely dependent on machine

*/
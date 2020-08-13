#include "B_FixedTimestep.h"
#include <chrono>

// Fixed Update, Fixed FPS
void Run_FixedTimestep(Game* game)
{

	while (game->IsRunning())
	{
		game->UpdateGame(TIME_UNIT(1.0f / Game::updateRate));								// Update with a fixed tick-rate (e.g. 60 steps per second).
		game->DisplayGame();																
		TIME_POINT nextUpdate = game->GetGameTime() + TIME_UNIT(1.0f / Game::updateRate);	// This is the gametime in the next round.
		game->Sleep(nextUpdate - NOW);														// Sleep the remaining time to the next round -> leads to fixed FPS, too.
	}

}

/*

+ Constant FPS
- Fast computers waste CPU time
- Slow computers lag behind

*/
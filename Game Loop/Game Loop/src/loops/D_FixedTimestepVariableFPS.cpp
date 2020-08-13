#include "D_FixedTimestepVariableFPS.h"
#include <chrono>

// Fixed Update, Variable FPS
void Run_FixedTimestepVariableFPS(Game* game)
{

	while (game->IsRunning())
	{

		while (game->GetGameTime() < NOW)							// While the gametime is behind, update.
		{
			game->UpdateGame(TIME_UNIT(1.0f / Game::updateRate));	// Update with a fixed tick-rate (e.g. 60 steps per second).
		}															// When display is slow, update is called more often per round to catch up.
																	// When update is slow, display is suspended -> lag. And has to catch up in next round.
		game->DisplayGame();										// When both are fast -> high FPS, constant update rate.
	}

}

/*

+ Constant FPS
+ Slow computers also have constant simulation speed
- Fast computers "waste" CPU/GPU time (more displays than needed)
- Slow computers produce lag, if update takes too long

*/
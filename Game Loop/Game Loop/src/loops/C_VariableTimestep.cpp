#include "C_VariableTimestep.h"
#include <chrono>

// Variable Update, Variable FPS
void Run_VariableTimestep(Game* game)
{

	while (game->IsRunning())
	{
		TIME_UNIT elapsedSeconds = NOW - game->GetGameTime();	// First round: 0. Then: time to update & display.
		game->UpdateGame(elapsedSeconds);						// Update the real time that elapsed in the last round.
		game->DisplayGame();									
	}

}

/*

+ Game time matches real time (good for real-time simulations)
- Fast computers have very small updates -> numerical instability
- Slow computers have big simulation steps

*/
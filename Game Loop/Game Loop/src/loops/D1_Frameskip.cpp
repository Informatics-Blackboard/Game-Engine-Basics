#include "D1_Frameskip.h"
#include <chrono>

// Fixed Update, Variable FPS + lag-avoidance
void Run_Frameskip(Game* game)
{

	int maxFrameSkip = 5;

	while (game->IsRunning())
	{
		int frames = 0;
		while (game->GetGameTime() < NOW && frames < maxFrameSkip)	// If it has to catch up too often, just leave the update alone.
		{
			game->UpdateGame(TIME_UNIT(1.0f / Game::updateRate));
			frames++;												// Count how often the simulation had to catch up with the last round.
		}

		if (frames >= maxFrameSkip)									// If it had to catch up too often, just skip the simulation to now.
		{
			game->SetGameTime(NOW);
		}

		game->DisplayGame();
	}

}

/*

+ Constant FPS
+ Slow computers also have constant simulation speed
+ Slow computers' simulation catches up directly, if it takes too long
- Fast computers "waste" CPU/GPU time (more displays than needed)

*/
#include <thread>

#include "Game.h"
#include "demonstration/Window.h"

#include "loops/A_SimpleLoop.h"
#include "loops/B_FixedTimestep.h"
#include "loops/C_VariableTimestep.h"
#include "loops/D_FixedTimestepVariableFPS.h"
#include "loops/D1_Frameskip.h"

// Setting everything up.
void Game::Init()
{
	OpenWindow();

	mGameTime = NOW;

	mRunning = true;
}

// The game loop - updating & rendering
void Game::Run()
{
	Run_SimpleLoop(this);
}

// Freeing resources
void Game::Cleanup()
{
	CloseWindow();
}

void Game::UpdateGame(TIME_UNIT timestep)
{
	mGameTime += timestep;
}

void Game::DisplayGame()
{
	UpdateWindow();
}

void Game::Sleep(TIME_UNIT time)
{
	std::this_thread::sleep_for(time);
}

bool Game::IsRunning()
{
	mRunning = !WindowShouldClose();
	return mRunning;
}

TIME_POINT Game::GetGameTime()
{
	return mGameTime;
}

void Game::SetGameTime(TIME_POINT time)
{
	mGameTime = time;
}

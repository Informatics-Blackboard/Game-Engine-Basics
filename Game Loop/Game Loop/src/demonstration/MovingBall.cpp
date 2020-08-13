#include <thread>

#include "MovingBall.h"

void MovingBall::initBallPos(TIME_POINT initialGameTime)
{
	mGameTime = initialGameTime;
	mXPos = 0.0f;
}

void MovingBall::moveBallPos(TIME_POINT newGameTime)
{
	TIME_UNIT timeDifference = mGameTime - newGameTime;
	// Move 10px per s: if the time difference is 1/30s move 1/3px
	mXPos += timeDifference.count() * 1 / 3.0f;

	// Simulate slow machine (1 machine speed unit = 1/20th of a 30fps-frame)
	std::this_thread::sleep_for(TIME_UNIT((100 - UPDATE_SPEED) * (1 / 20.0f) * (1 / 30.0f)));
}

void MovingBall::displayBall()
{
	// Draw OpenGL point at given position

	// Simulate slow machine (1 machine speed unit = 1/20th of a 30fps-frame)
	std::this_thread::sleep_for(TIME_UNIT((100 - DISPLAY_SPEED) * (1 / 20.0f) * (1 / 30.0f)));
}

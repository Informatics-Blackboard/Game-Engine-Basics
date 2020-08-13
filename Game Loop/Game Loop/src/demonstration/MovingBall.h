#pragma once

#include "Game.h"

// 100% = no delay, 80% = one 30fps frame delay, 60% = two 30fps frames delay, ..., 0% = five 30fps frames delay
#define UPDATE_SPEED 100
#define DISPLAY_SPEED 100

class MovingBall
{
public:
	void initBallPos(TIME_POINT initialGameTime);
	void moveBallPos(TIME_POINT newGameTime);
	void displayBall();

private:
	float mXPos;
	TIME_POINT mGameTime;
};
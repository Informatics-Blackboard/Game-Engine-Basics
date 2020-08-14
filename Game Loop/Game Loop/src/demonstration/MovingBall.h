#pragma once

#include "glad/glad.h"

#include "Game.h"

// TODO: More intuitive values.
// 100% = no delay, 80% = one 30fps frame delay, 60% = two 30fps frames delay, ..., 0% = five 30fps frames delay
#define UPDATE_SPEED 50
#define DISPLAY_SPEED 100

class MovingBall
{
public:
	static void initBallPos(TIME_POINT initialGameTime);
	static void moveBallPos(TIME_POINT newGameTime);
	static void displayBall();

private:
	static float sXPos;
	static TIME_POINT sGameTime;
	static GLuint sVAOPoint;
	static GLuint sArrayBufferPoint;
	static TIME_POINT sPreviousTimeMeasurement;

private:
	static void initDisplay();
};
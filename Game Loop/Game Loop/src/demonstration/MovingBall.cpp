#include <thread>
#include <iostream>

#include "MovingBall.h"
#include "Window.h"

float MovingBall::sXPos = 0.0f;
TIME_POINT MovingBall::sGameTime = NOW;
GLuint MovingBall::sArrayBufferPoint = 0;

void MovingBall::initBallPos(TIME_POINT initialGameTime)
{
	sGameTime = initialGameTime;
	sXPos = - getWindowWidth() / 2;

	initDisplay();
}

void MovingBall::initDisplay()
{
	// OpenGL error handling
	glDebugMessageCallback(
		[](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
		{
			std::cerr << source << ", " << type << ", " << id << ", " << severity << ", " << length << ", " << message << std::endl;
		}
	, nullptr);

	// VAO
	GLuint vaoPoint;
	glGenVertexArrays(1, &vaoPoint);
	glBindVertexArray(vaoPoint);

	// Array buffer & data
	glGenBuffers(1, &sArrayBufferPoint);
	glBindBuffer(GL_ARRAY_BUFFER, sArrayBufferPoint);

	// Program settings
	glClearColor(0, 0, 0.3, 1.0);
	glPointSize(50);
}

void MovingBall::moveBallPos(TIME_POINT newGameTime)
{
	TIME_UNIT timeDifference = newGameTime - sGameTime;
	// Move 10px per s: if the time difference is 1/30s move 1/3px
	sXPos += timeDifference.count() * 1 / 3.0f;

	sGameTime = newGameTime;

	// Simulate slow machine (1 machine speed unit = 1/20th of a 30fps-frame)
	std::this_thread::sleep_for(TIME_UNIT((100 - UPDATE_SPEED) * (1 / 20.0f) * (1 / 30.0f)));
}

void MovingBall::displayBall()
{
	// Draw OpenGL point at given position
	glClear(GL_COLOR_BUFFER_BIT);
	float pos[2] = { sXPos, getWindowHeight() / 2.0f };
	glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(float), pos, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, sArrayBufferPoint);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_POINTS, 0, 2);
	glDisableVertexAttribArray(0);

	// Simulate slow machine (1 machine speed unit = 1/20th of a 30fps-frame)
	std::this_thread::sleep_for(TIME_UNIT((100 - DISPLAY_SPEED) * (1 / 20.0f) * (1 / 30.0f)));
}

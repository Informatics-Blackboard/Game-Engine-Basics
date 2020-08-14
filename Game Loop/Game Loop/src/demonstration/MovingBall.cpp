#include <thread>
#include <iostream>

#include "MovingBall.h"
#include "Window.h"

// Static variable initialization
float MovingBall::sXPos = 0.0f;
TIME_POINT MovingBall::sGameTime = NOW;
GLuint MovingBall::sVAOPoint = 0;
GLuint MovingBall::sArrayBufferPoint = 0;
TIME_POINT MovingBall::sPreviousTimeMeasurement = NOW;
float initialBallOffset = -0.75;

void MovingBall::initBallPos(TIME_POINT initialGameTime)
{
	sGameTime = initialGameTime;
	sXPos = initialBallOffset;

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

	// Array buffer & data
	glGenBuffers(1, &sArrayBufferPoint);
	glBindBuffer(GL_ARRAY_BUFFER, sArrayBufferPoint);
	const float pos[2] = { sXPos, 0 };
	glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(float), pos, GL_STREAM_DRAW);

	// VAO
	glGenVertexArrays(1, &sVAOPoint);
	glBindVertexArray(sVAOPoint);

	// Program settings
	glClearColor(0, 0, 0.3f, 1.0f);
	glPointSize(50);
}

void MovingBall::moveBallPos(TIME_POINT newGameTime)
{
	TIME_UNIT timeDifference = newGameTime - sGameTime;
	// Move 0.1 in NDC per s.
	sXPos += timeDifference.count() * 0.1f;

	sGameTime = newGameTime;

	// Simulate slow machine (1 machine speed unit = 1/20th of a 30fps-frame)
	std::this_thread::sleep_for(TIME_UNIT((100 - UPDATE_SPEED) * (1 / 20.0f) * (1 / 30.0f)));
}

void MovingBall::displayBall()
{
	// Draw OpenGL point at given position
	glClear(GL_COLOR_BUFFER_BIT);
	// Vertex buffer binding & data
	glBindBuffer(GL_ARRAY_BUFFER, sArrayBufferPoint);
	const float pos[2] = { sXPos, 0 };
	glInvalidateBufferData(sArrayBufferPoint);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 2 * sizeof(float), pos);
	// VAO binding & data
	glBindVertexArray(sVAOPoint);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	// Drawing
	glDrawArrays(GL_POINTS, 0, 1);
	// Unbinding
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	TIME_UNIT timeBetweenFrames = NOW - sPreviousTimeMeasurement;
	sPreviousTimeMeasurement = NOW;

	std::cout << "FPS: " << float(1 / timeBetweenFrames.count()) << std::endl;

	// Simulate slow machine (1 machine speed unit = 1/20th of a 30fps-frame)
	std::this_thread::sleep_for(TIME_UNIT((100 - DISPLAY_SPEED) * (1 / 20.0f) * (1 / 30.0f)));
}

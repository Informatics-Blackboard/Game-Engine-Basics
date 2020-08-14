#include "Window.h"
#include <string>
#include <iostream>

void OpenWindow()
{
	if (glfwInit())

	{
		glfwSetErrorCallback(
			[](int error, const char* description) { std::cerr << "GLFW Error " + std::to_string(error) + ": " + std::string(description) << std::endl; });

		// Prevent 60FPS cap
		glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);
		window = glfwCreateWindow(getWindowWidth(), getWindowHeight(), "Game Loop", NULL, NULL);
		if (!window)
		{
			std::cerr << "Window creation failed!" << std::endl;
			return;
		}
		glfwMakeContextCurrent(window);
		if (!gladLoadGL())
		{
			std::cerr << "Loading OpenGL failed!" << std::endl;
			return;
		}
		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) { glfwSetWindowShouldClose(window, GLFW_TRUE); });
	}
}

void UpdateWindow()
{
	if (!WindowShouldClose())
	{
		glFlush();
		glfwPollEvents();
	}
}

void CloseWindow()
{
	glfwDestroyWindow(window);
}

bool WindowShouldClose()
{
	return glfwWindowShouldClose(window);
}

int getWindowHeight()
{
	return 480;
}

int getWindowWidth()
{
	return 640;
}

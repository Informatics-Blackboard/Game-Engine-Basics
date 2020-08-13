#include "Window.h"
#include <string>
#include <iostream>

void OpenWindow()
{
	if (glfwInit())

	{
		glfwSetErrorCallback(
			[](int error, const char* description) { std::cerr << "GLFW Error " + std::to_string(error) + ": " + std::string(description) << std::endl; });
		window = glfwCreateWindow(640, 480, "Game Loop", NULL, NULL);
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

		glfwSwapInterval(1);
	}
}

void UpdateWindow()
{
	if (!WindowShouldClose())
	{
		glfwSwapBuffers(window);
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

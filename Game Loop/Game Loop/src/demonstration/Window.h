#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void OpenWindow();
void UpdateWindow();
void CloseWindow();

bool WindowShouldClose();

static GLFWwindow* window;
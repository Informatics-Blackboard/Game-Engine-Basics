#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void OpenWindow();
void UpdateWindow();
void CloseWindow();

bool WindowShouldClose();

int getWindowHeight();
int getWindowWidth();

static GLFWwindow* window;
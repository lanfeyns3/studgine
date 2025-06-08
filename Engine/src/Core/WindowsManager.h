#ifndef SG_WINDOWSMANAGER
#define SG_WINDOWSMANAGER

#pragma once
#include "Window.h"
#include <vector>

namespace studgine
{
	namespace WindowsManager
	{

		Window& AddWindow(const char* name, int width, int height, GLFWwindow* share = nullptr);
		void UpdateWindows();

		void ShowWindow(unsigned int pos);
		void HideWindow(unsigned int pos);

		extern std::vector<Window> windows;
	}
}

#endif // !SG_WINDOWSMANAGER

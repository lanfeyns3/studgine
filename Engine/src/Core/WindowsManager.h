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

		void ShowWindow(uint32_t pos);
		void HideWindow(uint32_t pos);

		extern std::vector<Window> windows;
	}
}

#endif // !SG_WINDOWSMANAGER

#ifndef SG_WINDOWSMANAGER
#define SG_WINDOWSMANAGER

#pragma once
#include "Window.h"
#include "Events/Keystroke.h"
#include "Events/Shutdown.h"
#include "EventManager.h"
#include "ServiceLocator.h"
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

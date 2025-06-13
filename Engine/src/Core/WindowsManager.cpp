#include "WindowsManager.h"

namespace studgine
{
	namespace WindowsManager
	{

		std::vector<Window> windows;

		Window& AddWindow(const char* name, int width, int height, GLFWwindow* share)
		{
			windows.emplace_back(name, width, height, share);
			if (windows.size() == 1)
			{
				glfwMakeContextCurrent(windows.back().GetWindow());
			}
			return windows.back();
		}
		void UpdateWindows()
		{
			if (windows.size() > 0)
			{
				for (uint32_t i = 0; i < windows.size(); i++)
				{
					Window& window = windows.at(i);
					if (window.enabled == true)
						glfwSwapBuffers(window.GetWindow());
				}
			}
			
		}
		void ShowWindow(uint32_t pos)
		{
			Window& window = windows.at(pos);
			glfwShowWindow(window.GetWindow());
			window.enabled = true;
		}
		void HideWindow(uint32_t pos)
		{
			Window& window = windows.at(pos);
			glfwHideWindow(window.GetWindow());
			window.enabled = false;
		}
	}
}

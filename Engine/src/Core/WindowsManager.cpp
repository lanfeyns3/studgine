#include "WindowsManager.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		studgine::EventManager::AddEvent<studgine::Events::Keystroke>(key);
}

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
			glfwSetKeyCallback(windows.back().GetWindow(), key_callback);
			return windows.back();
		}
		void UpdateWindows()
		{
			if (windows.size() > 0)
			{
				for (uint32_t i = 0; i < windows.size(); i++)
				{
					Window& window = windows.at(i);
					if (glfwWindowShouldClose(window.GetWindow()))
					{
						glfwDestroyWindow(window.GetWindow());
						windows.erase(windows.begin() + i);
					}
					else
					{
						if (window.enabled == true)
							glfwSwapBuffers(window.GetWindow());
					}
				}
			}
			else
			{
				EventManager::AddEvent<Events::Shutdown>();
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

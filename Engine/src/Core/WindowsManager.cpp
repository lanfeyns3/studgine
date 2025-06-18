#include "WindowsManager.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		studgine::ServiceLocator::GetInstance().GetService<studgine::EventManager>()->AddEvent<studgine::Events::Keystroke>(key);
}

namespace studgine
{

	Window& WindowsManager::AddWindow(const char* name, int width, int height, GLFWwindow* share)
	{
		windows.emplace_back(name, width, height, share);
		if (windows.size() == 1)
		{
			glfwMakeContextCurrent(windows.back().GetWindow());
		}
		glfwSetKeyCallback(windows.back().GetWindow(), key_callback);
		return windows.back();
	}
	void WindowsManager::UpdateWindows()
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
			ServiceLocator::GetInstance().GetService<EventManager>()->AddEvent<Events::Shutdown>();
		}

	}
	void WindowsManager::ShowWindow(uint32_t pos)
	{
		Window& window = windows.at(pos);
		glfwShowWindow(window.GetWindow());
		window.enabled = true;
	}
	void WindowsManager::HideWindow(uint32_t pos)
	{
		Window& window = windows.at(pos);
		glfwHideWindow(window.GetWindow());
		window.enabled = false;
	}
}

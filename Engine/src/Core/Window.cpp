#include "Window.h"

namespace studgine
{
	Window::Window(const char* name, int width, int height, GLFWwindow* share)
	{

		if (!glfwInit())
		{
			ENGINE_LOG_CRITICAL("COULDN'T INIT GLFW");
		}
		m_window = glfwCreateWindow(width, height, name, NULL, share);
	}
	GLFWwindow*& Window::GetWindow()
	{
		return m_window;
	}
}
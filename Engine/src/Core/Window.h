#ifndef SG_WINDOW
#define SG_WINDOW

#include <GLFW/glfw3.h>
#include "Logging.h"

namespace studgine
{
	class Window
	{
	public:
		Window(const char* name, int width, int height, GLFWwindow* share = nullptr);

		GLFWwindow*& GetWindow();
	public:
		bool enabled = true;
	private:
		GLFWwindow* m_window;
	};
}
#endif // !SG_WINDOW

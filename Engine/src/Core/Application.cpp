#include "Application.h"

namespace studgine
{
	Application::Application()
	{
		InitLogging();
	}
	void Application::Run()
	{
		while (true)
		{
			LayerStack::UpdateLayers();
		}
	}
}
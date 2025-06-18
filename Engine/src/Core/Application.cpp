#include "Application.h"

namespace studgine
{
	Application::Application()
		: m_running(true)
	{
		InitLogging();
		ServiceLocator::GetInstance().GetService<EventManager>()->SubscribeFunction([this](void* data, uint32_t type) { Shutdown(data, type); }, Events::EventTypes::SHUTDOWN);
	}
	void Application::Run()
	{
		ServiceLocator& serviceLocator = ServiceLocator::GetInstance();
		while (m_running)
		{
			serviceLocator.GetService<LayerStack>()->UpdateLayers();
			serviceLocator.GetService<EventManager>()->PollEvents();
			serviceLocator.GetService<WindowsManager>()->UpdateWindows();
		}
	}
	void Application::Shutdown(void* data, uint32_t type)
	{
		ENGINE_LOG_INFO("Shutting down...");
		m_running = false;
	}
}
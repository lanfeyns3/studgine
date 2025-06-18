#include "EventManager.h"

namespace studgine
{
	void EventManager::PollEvents()
	{
		glfwPollEvents();

		std::vector<std::thread> threads;
		{
			std::unique_lock lock(m_eventsMutex);
			m_eventsFront = m_eventsBack;
			m_eventsBack.clear();
			m_eventsBack.clear();
		}

		for (auto& event : m_eventsFront)
		{
			threads.emplace_back([&]()
				{
					for (std::weak_ptr<Layers::Layer> layer : m_layers[event->GetType()])
					{
						if (auto content = layer.lock())
						{
							if (content->enabled)
							{
								content->OnEvent(event->GetData(), event->GetType());
							}
						}
					}
				});

			threads.emplace_back([&]()
				{
					for (auto function : m_functions[event->GetType()])
					{
						function(event->GetData(), event->GetType());
					}
				});
		}


		for (auto& thread : threads)
		{
			thread.join();
		}

		m_eventsFront.clear();

	}
	void EventManager::SubscribeLayer(std::shared_ptr<Layers::Layer> layer, uint32_t type)
	{
		m_layers[type].emplace_back(layer);
	}
	void EventManager::SubscribeFunction(std::function<void(void*, uint32_t)> function, uint32_t type)
	{
		m_functions[type].emplace_back(function);
	}
}
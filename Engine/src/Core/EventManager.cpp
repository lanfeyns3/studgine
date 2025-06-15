#include "EventManager.h"

namespace studgine
{
	
	namespace EventManager
	{
		std::shared_mutex g_eventsMutex;
		std::vector<Events::Event*> g_eventsFront;
		std::vector<Events::Event*> g_eventsBack;
		std::unordered_map<uint32_t, std::vector<std::weak_ptr<Layers::Layer>>> g_layers;
		std::unordered_map<uint32_t, std::vector<std::function<void(void*, uint32_t)>>> g_functions;
		void PollEvents()
		{
			glfwPollEvents();

			std::vector<std::thread> threads;
			{
				std::unique_lock lock(g_eventsMutex);
				g_eventsFront = g_eventsBack;
				g_eventsBack.clear();
				g_eventsBack.clear();
			}

			for (auto& event : g_eventsFront)
			{
				threads.emplace_back([&]()
					{
						for (std::weak_ptr<Layers::Layer> layer : g_layers[event->GetType()])
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
						for (auto function : g_functions[event->GetType()])
						{
							function(event->GetData(), event->GetType());
						}
					});
			}

			
			for (auto& thread : threads)
			{
				thread.join();
			}
			
			g_eventsFront.clear();
			
		}
		void SubscribeLayer(std::shared_ptr<Layers::Layer> layer, uint32_t type)
		{
			g_layers[type].emplace_back(layer);
		}
		void SubscribeFunction(std::function<void(void*, uint32_t)> function, uint32_t type)
		{
			g_functions[type].emplace_back(function);
		}
	}
}
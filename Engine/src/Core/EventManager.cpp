#include "EventManager.h"

namespace studgine
{
	
	namespace EventManager
	{
		std::vector<std::unique_ptr<Events::Event>> events;
		std::unordered_map<uint32_t, std::vector<std::weak_ptr<Layers::Layer>>> layers;
		void PollEvents()
		{
			glfwPollEvents();
			for (uint32_t i = 0; i < events.size(); i++)
			{
				auto& event = events.at(i);
				for (std::weak_ptr<Layers::Layer> layer : layers[event->GetType()])
				{
					if (auto content = layer.lock())
					{
						if (content->enabled)
						{
							content->OnEvent(event->GetData(),event->GetType());
						}
					}
				}
				event.release();
				events.erase(events.begin() + i);
			}
		}
		void SubscribeLayer(std::shared_ptr<Layers::Layer> layer, uint32_t type)
		{
			layers[type].emplace_back(layer);
		}
	}
}
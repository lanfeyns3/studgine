#ifndef SG_EVENTMANAGER
#define SG_EVENTMANAGER

#pragma once
#include "Events/Event.h"
#include "Layers/Layer.h"

#include <memory>
#include <vector>
#include <unordered_map>

#include<GLFW/glfw3.h>

namespace studgine
{
	namespace EventManager
	{

		template <typename T,typename... Args>
		void AddEvent(Args&&... args)
		{
			events.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
		};

		void PollEvents();
		void SubscribeLayer(std::shared_ptr<Layers::Layer> layer,uint32_t type);

		extern std::vector<std::unique_ptr<Events::Event>> events;
		extern std::unordered_map<uint32_t, std::vector<std::weak_ptr<Layers::Layer>>> layers;
	}
}
#endif // !SG_EVENTMANAGER

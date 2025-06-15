#ifndef SG_EVENTMANAGER
#define SG_EVENTMANAGER

#pragma once
#include "Events/Event.h"
#include "Layers/Layer.h"

#include <memory>
#include <vector>
#include <unordered_map>
#include <shared_mutex>
#include <thread>
#include <functional>

#include<GLFW/glfw3.h>

namespace studgine
{
	namespace EventManager
	{

		template <typename T,typename... Args>
		void AddEvent(Args&&... args)
		{
			std::unique_lock lock(g_eventsMutex);
			g_eventsBack.emplace_back(new T(std::forward<Args>(args)...));
		};

		void PollEvents();
		void SubscribeLayer(std::shared_ptr<Layers::Layer> layer,uint32_t type);
		void SubscribeFunction(std::function<void(void*, uint32_t)> function, uint32_t type);

		extern std::shared_mutex g_eventsMutex;
		extern std::vector<Events::Event*> g_eventsFront;
		extern std::vector<Events::Event*> g_eventsBack;
		extern std::unordered_map<uint32_t, std::vector<std::weak_ptr<Layers::Layer>>> g_layers;
		extern std::unordered_map<uint32_t, std::vector<std::function<void(void*, uint32_t)>>> g_functions;
	}
}
#endif // !SG_EVENTMANAGER

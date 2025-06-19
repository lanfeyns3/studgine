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
#ifdef __linux__
#include <mutex>
#endif

#include<GLFW/glfw3.h>

namespace studgine
{
	class EventManager
	{
	public:
		template <typename T, typename... Args>
		void AddEvent(Args&&... args)
		{
			std::unique_lock lock(m_eventsMutex);
			m_eventsBack.emplace_back(new T(std::forward<Args>(args)...));
		};

		void PollEvents();
		void SubscribeLayer(std::shared_ptr<Layers::Layer> layer, uint32_t type);
		void SubscribeFunction(std::function<void(void*, uint32_t)> function, uint32_t type);
	private:
		std::shared_mutex m_eventsMutex;
		std::vector<Events::Event*> m_eventsFront;
		std::vector<Events::Event*> m_eventsBack;
		std::unordered_map<uint32_t, std::vector<std::weak_ptr<Layers::Layer>>> m_layers;
		std::unordered_map<uint32_t, std::vector<std::function<void(void*, uint32_t)>>> m_functions;
	};
}
#endif // !SG_EVENTMANAGER

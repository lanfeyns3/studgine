#pragma once
#include "Event.h"

namespace studgine
{
	namespace Events
	{
		class Shutdown : public Event
		{
		public:

			void* GetData()
			{
				return nullptr;
			}
			uint32_t GetType()
			{
				return EventTypes::SHUTDOWN;
			}
		};
	}
}
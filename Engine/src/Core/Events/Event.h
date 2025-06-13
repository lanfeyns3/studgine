#ifndef SG_EVENT
#define SG_EVENT

#pragma once
#include "stdint.h"

namespace studgine
{
	namespace Events
	{
		enum EventTypes
		{
			ALL,
			KEYSTROKE,
		};

		class Event
		{
		public:
			virtual void* GetData() = 0;
			virtual uint32_t GetType() { return EventTypes::ALL; }
		};
	}
}

#endif // !SG_EVENTMANAGER

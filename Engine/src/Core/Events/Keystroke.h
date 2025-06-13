
#pragma once
#include "Event.h"

namespace studgine
{
	namespace Events
	{
		class Keystroke : public Event
		{
		public:
			Keystroke(uint32_t key)
				: data(key)
			{

			}

			void* GetData()
			{
				return (void*)&data;
			}
			uint32_t GetType()
				 override
			{
				return EventTypes::KEYSTROKE;
			}
		private:
			uint32_t data;
		};
	}
}
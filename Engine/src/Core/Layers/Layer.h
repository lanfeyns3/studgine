
#ifndef STUD_LAYER
#define STUD_LAYER

#pragma once
#include <stdint.h>

namespace studgine
{
	namespace Layers
	{
		class Layer
		{
		public:
			Layer() = default;

			virtual void OnAdded() = 0;
			virtual void OnRemoved() = 0;
			virtual void OnUpdate() = 0;
			virtual void OnEvent(void* data,uint32_t type) = 0;

			void Toggle()
			{
				enabled = !enabled;
			};
		public:
			bool enabled = true;
		};
	}
}
#endif // !STUD_LAYER

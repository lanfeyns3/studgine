#include "Engine.h"

namespace studgine
{
	namespace Layers
	{
		class EditorLayer : public Layer
		{
		public:

			void OnAdded()
			{
				CLIENT_LOG_INFO("Added EditorLayer");
			}
			void OnRemoved()
			{

			}
			void OnUpdate()
			{
				
			}
			void OnEvent()
			{

			}


		};
	}
}
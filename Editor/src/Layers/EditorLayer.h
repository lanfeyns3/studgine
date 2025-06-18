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
				CLIENT_LOG_INFO("Adding Editor Window");
				WindowsManager::AddWindow("Studgine Editor", 1280, 720);
				CLIENT_LOG_INFO("Window added Succesfully");

				ServiceLocator::GetInstance().GetService<EventManager>()->SubscribeLayer(LayerStack::Get(0),Events::EventTypes::KEYSTROKE);
			}
			void OnRemoved()
			{

			}
			void OnUpdate()
			{
				
			}
			void OnEvent(void* data, uint32_t type)
			{
				uint32_t result = *(uint32_t*)data;
				CLIENT_LOG_INFO(result);

				if (result == GLFW_KEY_ESCAPE)
				{
					ServiceLocator::GetInstance().GetService<EventManager>()->AddEvent<Events::Shutdown>();
				}
			}
		};
	}
}
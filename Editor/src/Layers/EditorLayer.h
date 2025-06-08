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
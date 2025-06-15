#ifndef SG_APPLICATION
#define SG_APPLICATION
#include "LayerStack.h"
#include "Logging.h"
#include "WindowsManager.h"
#include "EventManager.h"

namespace studgine
{
	class Application
	{
	public:
		Application();
		~Application() = default;

		void Run();
		void Shutdown(void* data, uint32_t type);
	private:
		bool m_running;
	};
}

#endif // !SG_APPLICATION

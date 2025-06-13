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
	};
}

#endif // !SG_APPLICATION

#ifndef STUD_APPLICATION
#include "LayerStack.h"
#include "Logging.h"
#define STUD_APPLICATION

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

#endif // !STUD_APPLICATION

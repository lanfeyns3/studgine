
#ifndef STUD_LAYER
#define STUD_LAYER
namespace studgine
{
	namespace Layers
	{
		class Layer
		{
		public:
			virtual void OnAdded() = 0;
			virtual void OnRemoved() = 0;
			virtual void OnUpdate() = 0;
			virtual void OnEvent() = 0;
		};
	}
}
#endif // !STUD_LAYER

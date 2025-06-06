#include "Layers/Layer.h"
#include <vector>

namespace studgine
{
	namespace LayerStack
	{

		const void AddLayer(Layers::Layer* layer);
		const void RemoveLayer(Layers::Layer* layer);

		const void UpdateLayers();

		extern std::vector<Layers::Layer*> layers;
	}
}
#include "LayerStack.h"

namespace studgine
{
	namespace LayerStack
	{

		std::vector<std::shared_ptr<Layers::Layer>> layers;

		const void UpdateLayers()
		{
			for (auto& layer : layers)
			{
				if (layer->enabled)
					layer->OnUpdate();
			}
		}
	}
}

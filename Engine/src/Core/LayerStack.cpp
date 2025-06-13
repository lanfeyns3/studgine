#include "LayerStack.h"

namespace studgine
{
	namespace LayerStack
	{

		std::vector<std::shared_ptr<Layers::Layer>> layers;

		const std::shared_ptr<Layers::Layer> Get(uint32_t pos)
		{
			return layers.at(pos);
		}

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

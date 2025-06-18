#include "LayerStack.h"

namespace studgine
{
	std::shared_ptr<Layers::Layer> LayerStack::Get(uint32_t pos)
	{
		return layers.at(pos);
	}

	void LayerStack::UpdateLayers()
	{
		for (auto& layer : layers)
		{
			if (layer->enabled)
				layer->OnUpdate();
		}
	}
}

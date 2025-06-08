#include "LayerStack.h"

namespace studgine
{
	namespace LayerStack
	{

		std::vector<Layers::Layer*> layers;

		const void AddLayer(Layers::Layer* layer)
		{
			layers.emplace_back(layer);
			auto& newLayer = layers.back();
			newLayer->OnAdded();
		}
		const void RemoveLayer(Layers::Layer* layer)
		{
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

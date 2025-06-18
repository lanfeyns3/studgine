#ifndef SG_LAYERSTACK
#define SG_LAYERSTACK

#pragma once
#include "Layers/Layer.h"

#include <memory>
#include <vector>

namespace studgine
{
	class LayerStack
	{
	public:
		template <typename T>
		inline void AddLayer()
		{
			layers.emplace_back(std::make_shared<T>());
			layers.back()->OnAdded();
		};

		std::shared_ptr<Layers::Layer> Get(uint32_t pos);

		void UpdateLayers();

	private:
		std::vector<std::shared_ptr<Layers::Layer>> layers;
	};
}
#endif // !SG_LAYERSTACK

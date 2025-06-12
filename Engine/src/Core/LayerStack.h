#ifndef SG_LAYERSTACK
#define SG_LAYERSTACK

#pragma once
#include "Layers/Layer.h"

#include <memory>
#include <vector>

namespace studgine
{
	namespace LayerStack
	{
		template <typename T>
		inline void AddLayer()
		{
			layers.emplace_back(std::make_shared<T>());
			layers.back()->OnAdded();
		};

		const void UpdateLayers();

		extern std::vector<std::shared_ptr<Layers::Layer>> layers;
	}
}
#endif // !SG_LAYERSTACK

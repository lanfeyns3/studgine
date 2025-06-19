#ifndef SG_RENDERER2D
#define SG_RENDERER2D

#pragma once
#include <vector>
#include <string>
#include <vulkan/vulkan.h>
#include "../../Core/Logging.h"

namespace studgine
{

	class Renderer2D
	{
	public:
		Renderer2D() = default;

	public:
		VkInstance vkInstance;
		const std::vector<const char*> validationLayers =
		{
			"VK_LAYER_KHRONOS_validation"
		};



#ifdef NDEBUG
		const bool enabledValidationLayers = false;
#else
		const bool enabledValidationLayers = true;
#endif
	};
}

#endif // !SG_RENDERER2D

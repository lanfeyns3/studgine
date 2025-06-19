#include "Window.h"

namespace studgine
{
	Window::Window(const char* name, int width, int height, GLFWwindow* share)
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		if (!glfwInit())
		{
			ENGINE_LOG_CRITICAL("COULDN'T INIT GLFW");
		}
		m_window = glfwCreateWindow(width, height, name, NULL, share);

		auto& instance = ServiceLocator::GetInstance().GetService<Renderer2D>()->vkInstance;
		auto& validationLayers = ServiceLocator::GetInstance().GetService<Renderer2D>()->validationLayers;
		auto& getValidation = ServiceLocator::GetInstance().GetService<Renderer2D>()->enabledValidationLayers;


		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = name;
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "studgine";
		appInfo.engineVersion = VK_MAKE_VERSION(0, 1, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtenstionCount = 0;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtenstionCount);
		
		createInfo.enabledExtensionCount = glfwExtenstionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		if (getValidation)
		{
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else
		{
			createInfo.enabledLayerCount = 0;
		}

		

		if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
		{
			ENGINE_LOG_CRITICAL("COULDNT MAKE A VKINSTANCE");
		}

	}
	GLFWwindow*& Window::GetWindow()
	{
		return m_window;
	}
}
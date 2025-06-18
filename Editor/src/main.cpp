#include "Engine.h"

#include "Layers/EditorLayer.h"

int main()
{
	studgine::Application app;
	studgine::ServiceLocator::GetInstance().GetService<studgine::LayerStack>()->AddLayer<studgine::Layers::EditorLayer>();

	app.Run();
}
#include "Engine.h"

#include "Layers/EditorLayer.h"

int main()
{
	studgine::Application app;
	studgine::LayerStack::AddLayer<studgine::Layers::EditorLayer>();

	app.Run();
}
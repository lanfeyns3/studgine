#include "Logging.h"

void studgine::InitLogging()
{
	auto engine = spdlog::stdout_color_mt("ENGINE");
	auto console = spdlog::stdout_color_mt("CLIENT");
}

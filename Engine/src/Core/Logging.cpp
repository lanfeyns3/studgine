#include "Logging.h"

namespace studgine
{
	Logging::Logging()
	{
		spdlog::set_pattern("%^[%n][%T]: %v%$");
		engine = spdlog::stdout_color_mt("ENGINE");
		client = spdlog::stdout_color_mt("CLIENT");
	}
}

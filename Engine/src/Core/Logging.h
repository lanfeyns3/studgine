#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include "../DLL.h"
#include "ServiceLocator.h"
#undef Logging

namespace studgine
{
	class SG_DLL Logging
	{
	public:
		Logging();
	public:
		std::shared_ptr<spdlog::logger> engine;
		std::shared_ptr<spdlog::logger> client;
	};
}

#define ENGINE_LOG_TRACE(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->engine->trace(msg)
#define ENGINE_LOG_DEBUG(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->engine->debug(msg)
#define ENGINE_LOG_INFO(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->engine->info(msg)
#define ENGINE_LOG_WARN(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->engine->warn(msg)
#define ENGINE_LOG_ERROR(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->engine->error(msg)
#define ENGINE_LOG_CRITICAL(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->engine->critical(msg)

#define CLIENT_LOG_TRACE(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->client->trace(msg)
#define CLIENT_LOG_DEBUG(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->client->debug(msg)
#define CLIENT_LOG_INFO(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->client->info(msg)
#define CLIENT_LOG_WARN(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->client->warn(msg)
#define CLIENT_LOG_ERROR(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->client->error(msg)
#define CLIENT_LOG_CRITICAL(msg) studgine::ServiceLocator::GetInstance().GetService<studgine::Logging>()->client->critical(msg)
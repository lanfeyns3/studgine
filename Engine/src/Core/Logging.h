#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include "../DLL.h"
#include "ServiceLocator.h"

namespace studgine
{

}

#define ENGINE_LOG_TRACE(msg) spdlog::get("ENGINE")->trace(msg)
#define ENGINE_LOG_DEBUG(msg) spdlog::get("ENGINE")->debug(msg)
#define ENGINE_LOG_INFO(msg) spdlog::get("ENGINE")->info(msg)
#define ENGINE_LOG_WARN(msg) spdlog::get("ENGINE")->warn(msg)
#define ENGINE_LOG_ERROR(msg) spdlog::get("ENGINE")->error(msg)
#define ENGINE_LOG_CRITICAL(msg) spdlog::get("ENGINE")->critical(msg)

#define CLIENT_LOG_TRACE(msg) spdlog::get("CLIENT")->trace(msg)
#define CLIENT_LOG_DEBUG(msg) spdlog::get("CLIENT")->debug(msg)
#define CLIENT_LOG_INFO(msg) spdlog::get("CLIENT")->info(msg)
#define CLIENT_LOG_WARN(msg) spdlog::get("CLIENT")->warn(msg)
#define CLIENT_LOG_ERROR(msg) spdlog::get("CLIENT")->error(msg)
#define CLIENT_LOG_CRITICAL(msg) spdlog::get("CLIENT")->critical(msg)
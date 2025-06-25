cmake_minimum_required(VERSION "3.19.2")

set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("thirdparty/spdlog")
add_subdirectory("thirdparty/GLFW")
add_subdirectory("thirdparty/entt")

project(Logging)
add_library(Logging SHARED "Engine/src/Core/Logging.cpp" "Engine/src/Core/Logging.h" "Engine/src/DLL.h")
target_link_libraries(Logging PUBLIC spdlog)
target_include_directories(Logging PUBLIC "thirdparty/spdlog/include/")

add_compile_definitions(Logging COMPILE_DLL)

project(Engine)
add_library(Engine STATIC "Engine/src/Core/Application.cpp" "Engine/src/Core/LayerStack.cpp" "Engine/src/Core/Window.h" "Engine/src/Core/Window.cpp" "Engine/src/Core/WindowsManager.h" "Engine/src/Core/WindowsManager.cpp" "Engine/src/Core/Events/Event.h" "Engine/src/Core/EventManager.h" "Engine/src/Core/EventManager.cpp" "Engine/src/Core/Events/Keystroke.h" "Engine/src/Core/Events/Shutdown.h" "Engine/src/Core/ServiceLocator.cpp" "Engine/src/Core/ServiceLocator.h"  "Engine/src/DLL.h" "Engine/src/Core/ECS.h" "Engine/src/Core/ECS.cpp")
target_link_libraries(Engine PUBLIC glfw Logging)
target_include_directories(Engine PUBLIC "thirdparty/spdlog/include/" "thirdparty/GLFW/include/" "thirdparty/entt/single_include/")

project(Editor)
add_executable(Editor "Editor/src/main.cpp" "Engine/src/DLL.h" )
target_link_libraries(Editor PUBLIC Engine)
target_include_directories(Editor PUBLIC "Engine/src" "thirdparty/spdlog/include/" "thirdparty/GLFW/include/")
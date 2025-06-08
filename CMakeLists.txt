cmake_minimum_required(VERSION "3.19.2")

add_subdirectory("thirdparty/spdlog")
add_subdirectory("thirdparty/GLFW")

project(Engine)
add_library(Engine STATIC "Engine/src/Core/Application.cpp" "Engine/src/Core/LayerStack.cpp" "Engine/src/Core/Logging.cpp" "Engine/src/Core/Logging.h" "Engine/src/Core/Window.h" "Engine/src/Core/Window.cpp" "Engine/src/Core/WindowsManager.h" "Engine/src/Core/WindowsManager.cpp")
target_link_libraries(Engine PUBLIC spdlog glfw)
target_include_directories(Engine PUBLIC "thirdparty/spdlog/include/" "thirdparty/GLFW/include/")

project(Editor)
add_executable(Editor "Editor/src/main.cpp")
target_link_libraries(Editor PUBLIC Engine)
target_include_directories(Editor PUBLIC "Engine/src" "thirdparty/spdlog/include/" "thirdparty/GLFW/include/")
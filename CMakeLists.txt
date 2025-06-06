cmake_minimum_required(VERSION "3.19.2")

add_subdirectory("thirdparty/spdlog")

project(Engine)
add_library(Engine STATIC "Engine/src/Core/Application.cpp" "Engine/src/Core/LayerStack.cpp" "Engine/src/Core/Logging.cpp" "Engine/src/Core/Logging.h")
target_link_libraries(Engine PUBLIC spdlog)
target_include_directories(Engine PUBLIC "thirdparty/spdlog/include/")

project(Editor)
add_executable(Editor "Editor/src/main.cpp")
target_link_libraries(Editor PUBLIC Engine)
target_include_directories(Editor PUBLIC "Engine/src" "thirdparty/spdlog/include/")
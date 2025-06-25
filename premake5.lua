workspace "studgine
  configurations {"Debug","Release"}

project "Logging"
  kind "SharedLib"
  language "C++17"
  targetdir "bin/%{cfg.buildcfg}"

  files {"Engine/src/Core/Logging.cpp", "Engine/src/Core/Logging.h", "Engine/src/DLL.h"}

  includedirs {"thirdparty/spdlog

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

project "Engine"
  kind "StaticLib"
  language "C++17"
  targetdir "bin/%{cfg.buildcfg}"
  
  files {"Engine/src/**.h", "Engine/src/**.cpp"}
  removefiles {"Engine/src/Core/Logging.cpp", "Engine/src/Core/Logging.h", "Engine/src/DLL.h"}

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

project "Editor"
  kind "ConsoleApp"
  language "C++17"
  targetdir "bin/%{cfg.buildcfg}"

  files {"Editor/src/**.h", "Editor/src/**.cpp"}

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

workspace "Novl"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Libs/glfw/Include"

include "Libs/glfw"

project "Novl"
	location "Novl"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("int/" .. outputdir .."/%{prj.name}")

	pchheader "pch.h"
	pchsource "Novl/src/pch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"Libs/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"NOVL_PLATFORM_WINDOWS",
			"NOVL_ENABLE_ASSERTS",
			"NOVL_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Playground")
		}

	filter "configurations:Debug"
		defines "NOVL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NOVL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NOVL_DIST"
		optimize "On"

project "Playground"
	location "Playground"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Novl/src",
		"Libs/spdlog/include"
	}

	links{
		"Novl"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"NOVL_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "NOVL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NOVL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NOVL_DIST"
		optimize "On"
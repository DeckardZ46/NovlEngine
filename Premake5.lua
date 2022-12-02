workspace "Novl"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Novl"
	location "Novl"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("int/" .. outputdir .."/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"NOVL_PLATFORM_WINDOWS",
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
		"Novl/src"
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
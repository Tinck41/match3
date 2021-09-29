workspace "match3"
    architecture "x86"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}_%{cfg.system}-%{cfg.arhictecture}" 

include "match3/vendor/imgui"

project "match3"
    location "match3"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "%{prj.name}")

    pchheader "m3pch.h"
    pchsource "match3/src/m3pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/EnTT/include",
        "%{prj.name}/vendor/SFML-2.5.1/include",
        "%{prj.name}/vendor/imgui/include",
        "%{prj.name}/vendor/spdlog/include"
    }

    libdirs
    {
        "%{prj.name}/vendor/SFML-2.5.1/lib"
    }

    links 
    { 
        "opengl32.lib",
        "freetype.lib",
        "winmm.lib",
        "gdi32.lib",
        "openal32.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
        "ws2_32.lib",
        "ImGui"
    }

    filter "system:windows"
        cppdialect "c++17"
        systemversion "latest"

        defines
        {
            "SFML_STATIC"
        }
    
    filter "configurations:Debug"
        symbols "On"

        links 
        { 
            "sfml-audio-s-d.lib",
            "sfml-graphics-s-d.lib",
            "sfml-network-s-d.lib",
            "sfml-system-s-d.lib",
            "sfml-window-s-d.lib"
        }
    
    filter "configurations:Release"
        symbols "On"

        links 
        { 
            "sfml-audio-s.lib",
            "sfml-graphics-s.lib",
            "sfml-network-s.lib",
            "sfml-system-s.lib",
            "sfml-window-s.lib"
        }
    
    filter "configurations:Dist"
        symbols "On"

        links 
        { 
            "sfml-audio-s.lib",
            "sfml-graphics-s.lib",
            "sfml-network-s.lib",
            "sfml-system-s.lib",
            "sfml-window-s.lib"
        }


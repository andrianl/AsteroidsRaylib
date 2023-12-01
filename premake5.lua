-- Робочий простір (Workspace)
workspace "AsteroidsGame"
    configurations { "Debug", "Release" }
    platforms { "Win32", "Win64" }

-- Проект для компіляції Raylib в статичну бібліотеку
project "raylib"
    kind "StaticLib"
    language "C"
    targetdir ("Binary/%{cfg.buildcfg}/raylib")

    files
    {
        "raylib/src/*.c",
        "raylib/src/*.h"
    }

    includedirs
    {
        "raylib/src",
        "raylib/src/external/glfw/include/GLFW",
        "raylib/src",
        "raylib/src/external/glfw/include",
        "raylib/src/external/glfw/deps/mingw",
        "raylib/src/external/glfw/deps/mingw/glad",
        "raylib/src/external/glfw/deps/mingw/nanovg",
    }

    filter "system:windows"
        systemversion "latest"
        defines {"PLATFORM_DESKTOP"}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

-- Проект для гри Asteroids
project "Asteroids"
    kind "ConsoleApp"
    language "C++"
    targetdir ("Binary/%{cfg.buildcfg}/Asteroids")

    files
    {
        "Asteroids/Include/*.h",
        "Asteroids/Source/*.cpp"
    }

    includedirs
    {
        "Asteroids/Include",
        "raylib/src",
    }

    links
    {
        "raylib"
    }

    filter "system:windows"
        systemversion "latest"
        defines {"PLATFORM_DESKTOP"}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

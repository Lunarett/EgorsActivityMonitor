project "EgorsActivityMonitor"
    location "EgorsActivityMonitor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("../Intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "../ThirdParty/spdlog/include"
    }

    defines 
    { 
        "PLATFORM_WINDOWS"
    }

    filter "system:windows"
        systemversion "latest"
        characterset "Unicode"
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "on"
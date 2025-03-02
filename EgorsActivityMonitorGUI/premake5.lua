project "EgorsActivityMonitorGUI"
    location "EgorsActivityMonitorGUI"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("../Intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",
        "../ThirdParty/imgui/backends/imgui_impl_dx11.cpp",
        "../ThirdParty/imgui/backends/imgui_impl_win32.cpp",
        "../ThirdParty/imgui/*.cpp"
    }

    includedirs
    {
        "src",
        "../ThirdParty/imgui",
        "../ThirdParty/imgui/backends",
        "../ThirdParty/spdlog/include"
    }

    defines 
    { 
        "PLATFORM_WINDOWS",
        "IMGUI_IMPL_WIN32"
    }

    links
    {
        "d3d11.lib",
        "dxgi.lib",
        "dxguid.lib",
        "kernel32.lib",
        "user32.lib",
        "gdi32.lib",
        "winspool.lib",
        "comdlg32.lib",
        "advapi32.lib",
        "shell32.lib",
        "ole32.lib",
        "oleaut32.lib",
        "uuid.lib",
        "odbc32.lib",
        "odbccp32.lib"
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
workspace "EgorsActivityMonitor"
    architecture "x64"
    startproject "EgorsActivityMonitorGUI"

    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["ImGui"] = "ThirdParty/imgui"
    IncludeDir["ImGuiBackend"] = "ThirdParty/imgui/backends"
    IncludeDir["spdlog"] = "ThirdParty/spdlog/include"

    group "Applications"
        include "EgorsActivityMonitor"
        include "EgorsActivityMonitorGUI"
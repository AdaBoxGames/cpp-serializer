workspace "simple-cpp-serializer"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }



project "simple-cpp-serializer"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    objdir "%{wks.location}/bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    files
    {
        "include/scs/*.hpp",
        "src/*.cpp"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"
        location "simple-cpp-serializer"

        defines
        {
            "SCS_OS_WIN64"
        }
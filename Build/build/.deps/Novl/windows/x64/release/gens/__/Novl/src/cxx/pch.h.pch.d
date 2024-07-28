{
    depfiles_cl_json = "{\
    \"Version\": \"1.2\",\
    \"Data\": {\
        \"Source\": \"c:\\\\users\\\\decka\\\\projects\\\\novlengine\\\\build\\\\build\\\\.gens\\\\novl\\\\windows\\\\x64\\\\release\\\\__\\\\novl\\\\src\\\\pch.h\",\
        \"ProvidedModule\": \"\",\
        \"Includes\": [\
            \"c:\\\\users\\\\decka\\\\projects\\\\novlengine\\\\build\\\\build\\\\.gens\\\\novl\\\\windows\\\\x64\\\\release\\\\__\\\\novl\\\\src\\\\pch.h\",\
            \"c:\\\\users\\\\decka\\\\projects\\\\novlengine\\\\novl\\\\src\\\\pch.h\",\
            \"c:\\\\users\\\\decka\\\\projects\\\\novlengine\\\\novl\\\\src\\\\pch.h\"\
        ],\
        \"ImportedModules\": [],\
        \"ImportedHeaderUnits\": []\
    }\
}",
    files = {
        [[build\.gens\Novl\windows\x64\release\__\Novl\src\pch.h]]
    },
    values = {
        [[C:\Users\decka\Softwares\VisualStudio\2022\VC\Tools\MSVC\14.39.33519\bin\HostX64\x64\cl.exe]],
        {
            "-nologo",
            "-O2",
            "-std:c++20",
            "-MD",
            [[-I..\Novl\src]],
            [[-I..\Libs\glad\include]],
            [[-I..\Libs\glfw3\include]],
            [[-I..\Libs\ImGui\include]],
            "-DNOVL_RELEASE",
            "-DNOVL_PLAT_WINDOWS",
            "-DNOVL_BUILD_DLL",
            "/EHsc",
            [[-YuC:\Users\decka\Projects\NovlEngine\Build\build\.gens\Novl\windows\x64\release\__\Novl\src\pch.h]],
            [[-FIC:\Users\decka\Projects\NovlEngine\Build\build\.gens\Novl\windows\x64\release\__\Novl\src\pch.h]],
            [[-Fpbuild\release\windows_x64\obj\Novl\windows\x64\release\gens\__\Novl\src\cxx\pch.h.pch]],
            "-DNDEBUG"
        }
    }
}
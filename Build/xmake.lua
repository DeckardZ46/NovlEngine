--[[
< Novl Engine > xmake.lua
Author: DeckardZ46
Date: 2024/07/10
Note: This is xmake build file for Novl Engine
Codebase: https://github.com/DeckardZ46/NovlEngine
--]]

---------- BASIC SETTINGS ----------
set_project("Novl Engine")
set_version("0.0.1")
set_xmakever("2.9.3")

includes("xmakeUtils.lua")

-- build mode
set_allowedmodes("debug","release")
add_rules("mode.debug", "mode.release")
if is_mode("debug") then 
    add_defines("NOVL_DEBUG")
elseif is_mode("release") then 
    add_defines("NOVL_RELEASE")
end

set_targetdir("$(buildir)/$(mode)/$(plat)_$(arch)")
set_objectdir("$(buildir)/$(mode)/$(plat)_$(arch)/obj")

---------- PLATFORM ----------
-- supported platform
set_allowedplats("windows")
set_allowedarchs("windows|x64")

-- platform specified settings
option("plat_windows")
    add_defines("NOVL_PLAT_WINDOWS","NOVL_BUILD_DLL")
    set_languages("cxx20")
option_end()                       

---------- NOVL RUNTIME -------------
target("Novl")
    set_kind("shared")

    -- add file to target
    set_pcxxheader("../Novl/src/pch.h")
    add_files("../Novl/**.cpp")

    -- link to target
    -- ...

    -- platform specified settings
    if is_plat("windows") then 
        add_options("plat_windows")
    end

target_end()

---------- NOVL EDITOR --------------
target("Novl Editor")
    add_deps("Novl")
    set_kind("binary")

    -- add file to target
    add_files("../NovlEditor/**.cpp")
    add_includedirs("../Novl/src/Details")

    -- link to target
    -- ...

    -- platform specified settings
    if is_plat("windows") then 
        add_options("plat_windows")
    end
target_end()
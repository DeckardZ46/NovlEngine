--[[
< Novl Engine > xmake.lua
Author: DeckardZ46
Date: 2024/07/10
Note: This is xmake build file for Novl Engine
Codebase: https://github.com/DeckardZ46/NovlEngine
--]]

---------- NOVL RUNTIME -------------
target("Novl")
    set_kind("shared")
    add_files("")
target_end()

---------- NOVL EDITOR --------------
target("Novl Editor")
    set_kind("binary")
    add_files("")
target_end()
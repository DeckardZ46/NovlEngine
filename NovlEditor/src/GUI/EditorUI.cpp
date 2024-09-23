#include <pch.h>
#include "EditorUI.h"

#ifdef NOVL_PLAT_WINDOWS
    #include <glfw3.h>
    #include <imgui_impl_glfw.h>
    #include <imgui_impl_opengl3.h>
#include "EditorUI.h"
#endif


namespace Novl{
    EditorUI::EditorUI() {
        NLOGD("Initializing EditorUI...");

        // init Editor UI when constructing
        init();
    }

    EditorUI::~EditorUI(){

    }

    void EditorUI::init() {
        ImGuiUI::init();
    }

    void EditorUI::clear() {
        ImGuiUI::clear();
    }

    void EditorUI::update() {
        ImGuiUI::update();
    }

    void EditorUI::draw() {
        ImGuiUI::draw();
    }

} // namespace Novl
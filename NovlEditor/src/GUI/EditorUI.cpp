#include "EditorUI.h"
#include <pch.h>

#ifdef NOVL_PLAT_WINDOWS
#include "EditorUI.h"
#include <glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#endif

namespace Novl {
EditorUI::EditorUI() {
    NLOGD("Initializing EditorUI...");

    // create imgui context
    IMGUI_CHECKVERSION();
    if (!ImGui::GetCurrentContext()) {
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        ImGui::StyleColorsDark();
        io.Fonts->AddFontFromFileTTF("../../../../Assets/Fonts/Cousine-Regular.ttf", 14);
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    }

    // initialize imgui render backend, make sure AFTER creating imgui context
    ImGuiUI::init();
}

EditorUI::~EditorUI() {
    // order sensitive here
    ImGuiUI::clear();
    ImGui::DestroyContext();
}

void EditorUI::init() {
    // init panels
}

void EditorUI::clear() {
    // clear panels
}

void EditorUI::update() {
    ImGuiUI::update();
    ImGui::ShowDemoWindow();
}

void EditorUI::draw() {
    ImGuiUI::draw();
}

} // namespace Novl
#include "EditorUI.h"
#include <pch.h>

#ifdef NOVL_PLAT_WINDOWS
#include <glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#endif // NOVL_PLAT_WINDOWS

#include "Panels/ConsolePanel.h"

namespace Novl {
EditorUI::EditorUI() {
    ELOGD("Initializing EditorUI...");

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
    auto consolePanel = new ConsolePanel("ConsolePanel");
    m_panels.emplace_back(std::move(consolePanel));
}

void EditorUI::clear() {
    // clear panels
}

void EditorUI::update() {
    ImGuiUI::update();
    ImGui::ShowDemoWindow();
    if (m_panels.size() > 0) {
        for (auto panel : m_panels) {
            panel->update();
        }
    }
}

void EditorUI::draw() {
    ImGuiUI::draw();
    if (m_panels.size() > 0) {
        for (auto panel : m_panels) {
            EDITOR_ASSERT(panel != nullptr, "Editor UI: draw panel failed! Panel is null.");
            panel->draw();
        }
    }
}

} // namespace Novl
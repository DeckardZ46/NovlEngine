#include "ImGuiUI.h"
#include <Novl.h> // TODO: replace with a global window manager
#include <pch.h>

#ifdef NOVL_PLAT_WINDOWS
#include <glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#endif

namespace Novl {
ImGuiUI::ImGuiUI() {
}

ImGuiUI::~ImGuiUI() {
}

void ImGuiUI::init() {
    /*
        here we init imgui render backend, make sure init imgui context BEFORE this
     */
    NOVL_ASSERT(ImGui::GetCurrentContext() != nullptr,"Cannot get imgui context before init render backend for imgui!");
#ifdef NOVL_PLAT_WINDOWS
    void *glfwWindowPtr = NovlRuntime::Get().getWindow().getNativeWindow();
    NOVL_ASSERT(glfwWindowPtr != nullptr, "ImGuiUI: get native glfw window failed!");
    ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow *>(glfwWindowPtr), true);
    ImGui_ImplOpenGL3_Init("#version 460");
#endif // NOVL_PLAT_WINDOWS
}

void ImGuiUI::clear() {
    // clear imgui render backend, BEFORE delete imgui context
#ifdef NOVL_PLAT_WINDOWS
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
#endif // NOVL_PLAT_WINDOWS
}

void ImGuiUI::update() {
#ifdef NOVL_PLAT_WINDOWS
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
#endif // NOVL_PLAT_WINDOWS

    ImGui::NewFrame();
}

void ImGuiUI::draw() {
    ImGui::Render();

#ifdef NOVL_PLAT_WINDOWS
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif // NOVL_PLAT_WINDOWS
}

} // namespace Novl
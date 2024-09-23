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
    // init ImGui
    IMGUI_CHECKVERSION();
    if (!ImGui::GetCurrentContext()){
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        ImGui::StyleColorsDark();
        io.Fonts->AddFontFromFileTTF("../../../../Assets/Fonts/Cousine-Regular.ttf", 14);
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

#ifdef NOVL_PLAT_WINDOWS
        void* glfwWindowPtr = NovlRuntime::Get().getWindow().getNativeWindow();
        NOVL_ASSERT(glfwWindowPtr != nullptr, "ImGuiUI: get native glfw window failed!");
        ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(glfwWindowPtr), true);
        ImGui_ImplOpenGL3_Init("#version 460");
#endif // NOVL_PLAT_WINDOWS
    }
}

void ImGuiUI::clear(){
#ifdef NOVL_PLAT_WINDOWS
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
#endif // NOVL_PLAT_WINDOWS

        ImGui::DestroyContext();

        // after ImGui::DestroyContext(), context & io pointer should already be free
        m_context = nullptr;
        m_io = nullptr;
}

void ImGuiUI::update() {
#ifdef NOVL_PLAT_WINDOWS
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
#endif // NOVL_PLAT_WINDOWS

    ImGui::NewFrame();
    ImGui::ShowDemoWindow();
}

void ImGuiUI::draw() {
    ImGui::Render();

#ifdef NOVL_PLAT_WINDOWS
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif // NOVL_PLAT_WINDOWS
}

} // namespace Novl
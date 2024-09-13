#include <pch.h>
#include <glad.h>
#include "WindowsWindow.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Novl{
    static bool s_glfwInit = false;

    static void GLFWErrorCallback(int error, const char* description) {
		NLOGE("GLFW Error ({0}): {1}", error, description);
	}

    void FramebufferSizeChange_cb(GLFWwindow *window, int width, int height);

    WindowsWindow::WindowsWindow(const WindowData& wdata):m_data(wdata){
        init();
    }

    WindowsWindow::~WindowsWindow(){
        shutdown();
    }

    void WindowsWindow::init(){
        NLOGI("Creating Windows window [{0}]...\nwidth: {1}, height: {2}", m_data.title, m_data.width, m_data.height);

        // init glfw
        if(!s_glfwInit){
            s_glfwInit = glfwInit();
            NOVL_ASSERT(s_glfwInit,"glfw initialize failed!");

            // opengl settings
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, NOVL_OGL_VER_MAJ);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, NOVL_OGL_VER_MIN);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            glfwSetErrorCallback(GLFWErrorCallback);
        }

        // create window
        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
        NOVL_ASSERT(m_window != nullptr, "Failed to create glfw window!");
        glfwMakeContextCurrent(m_window);
        setVSync(true);

        // init OpenGL
        int stat = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        NOVL_ASSERT(stat, "Failed to initialize GLAD!");

        // set callback funtions
        glfwSetWindowUserPointer(m_window,&m_data);
        glfwSetFramebufferSizeCallback(m_window, FramebufferSizeChange_cb);

        // init ImGui 
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        ImGui::StyleColorsDark();
        io.Fonts->AddFontFromFileTTF("../../../../Assets/Fonts/Cousine-Regular.ttf",14);
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

        // platform specific initializing
#ifdef NOVL_PLAT_WINDOWS
        ImGui_ImplGlfw_InitForOpenGL(m_window, true);
        ImGui_ImplOpenGL3_Init("#version 460");
#endif
    }

    void WindowsWindow::shutdown(){
        // Destroy all windows
        glfwDestroyWindow(m_window);
        m_window = nullptr;

        // Terminate glfw program
        glfwTerminate();
    }

    void WindowsWindow::update(){
        glfwPollEvents();
        glClearColor(0.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(m_window);
    }


    void WindowsWindow::setVSync(bool enabled){
        if(enabled){
            glfwSwapInterval(1);
            m_isVSync = true;
        }else{
            glfwSwapInterval(0);
            m_isVSync = false;
        }
    }

    bool WindowsWindow::isClose() const{
        if(glfwWindowShouldClose(m_window)){
            return true;
        }else{
            return false;
        }
    }

    void FramebufferSizeChange_cb(GLFWwindow *window, int width, int height){
        glViewport(0,0,width,height);
    }

}
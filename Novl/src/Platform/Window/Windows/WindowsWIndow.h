#pragma once
#include <Details/Window/NovlWindow.h>
#include <glfw3.h>

namespace Novl {
class WindowsWindow final : public WindowBase {
  public:
    WindowsWindow(const WindowData &wdata);
    ~WindowsWindow();

    inline uint32_t getWidth() const override {
        return m_data.width;
    }
    inline uint32_t getHeight() const override {
        return m_data.height;
    }

    inline bool isVSync() const override {
        return m_isVSync;
    }
    bool isClose() const override;

  private:
    void init();
    void shutdown();

    void update() override;
    void endFrame() override;
    inline void setVSync(bool enabled) override;
    void *getNativeWindow() const override {
        return static_cast<void *>(m_window);
    }

  private:
    bool m_isVSync;
    GLFWwindow *m_window;
    WindowData m_data;
};
} // namespace Novl
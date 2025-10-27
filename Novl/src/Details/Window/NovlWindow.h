/**
 * < Novl Engine > NovlWindow.h
 * Author: DeckardZ46
 * Date: 2024/08/30
 * Note: This is abstract cross-platform window of Novl Engine
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

namespace Novl {
	struct WindowData {
		string title;
		uint32_t width;
		uint32_t height;

		WindowData( const string& title = "Novl Engine",
					uint32_t width = 1280,
					uint32_t height = 720)
				:title(title),width(width),height(height){}
	};

	// desktop windowBase
	class WindowBase {
		friend class NovlRuntime;
	public:
		virtual ~WindowBase() {}
		
		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		virtual bool isVSync() const = 0;
		virtual bool isClose() const = 0;

		float getDPIScale() const { return m_dpiScale; }

	protected:
		virtual void init() = 0;
		virtual void shutdown() = 0;	
		virtual void update() = 0;
		virtual void endFrame() = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual void* getNativeWindow() const = 0;
		virtual void setWindowCallBack() = 0;

		static WindowBase* Create(const WindowData& wdata = WindowData());

		float m_dpiScale = 1.0f;
	};

}
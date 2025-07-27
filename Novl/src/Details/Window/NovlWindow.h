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
		n_string title;
		uint32_t width;
		uint32_t height;

		WindowData( const n_string& title = "Novl Engine",
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

	protected:
		virtual void update() = 0;
		virtual void endFrame() = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual void* getNativeWindow() const = 0;

		static WindowBase* Create(const WindowData& wdata = WindowData());
	};

}
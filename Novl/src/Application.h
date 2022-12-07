#pragma once

#include "Window.h"

namespace Novl{
	class NOVL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	// To be defined in Client
	Application* CreateApplication();
}


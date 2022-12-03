#include "pch.h"
#include "Application.h"
#include "Event/MouseEvent.h"

namespace Novl {
	Application::Application() {

	};

	Application::~Application() {

	}

	void Application::Run() {
		// test event system
		MouseMovedEvent m(1, 2);
		std::cout << m.GetName() << " " << m.GetX() << "," << m.GetY() << std::endl;
	}
}
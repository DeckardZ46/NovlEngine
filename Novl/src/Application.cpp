#include "Application.h"
#include "Event/MouseEvent.h"
#include <iostream>

namespace Novl {
	Application::Application() {

	};

	Application::~Application() {

	}

	void Application::Run() {
		MouseMovedEvent m(1, 2);
		std::cout << m.GetName() << " " << m.GetX() << "," << m.GetY() << std::endl;
	}
}
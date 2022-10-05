#pragma once
#include "Application.h"

#ifdef NOVL_PLATFORM_WINDOWS

extern Novl::Application* Novl::CreateApplication();

int main(int argc, char** argv) {
	printf("Welcome to Novl Engine!");
	auto App = Novl::CreateApplication();
	App->Run();
	delete App;
}

#endif

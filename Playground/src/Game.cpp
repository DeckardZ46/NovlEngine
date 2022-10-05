#include "Novl.h"
class Game :public Novl::Application {
public:
	Game() {

	}

	~Game() {

	}

};

Novl::Application* Novl::CreateApplication() {
	return new Game();
}
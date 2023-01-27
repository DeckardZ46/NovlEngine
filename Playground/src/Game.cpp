#include "Novl.h"

class PlaygroundLayer : public Novl::Layer
{
public:
	PlaygroundLayer()
		:Layer()
	{

	}

	void OnUpdate() override
	{
		NOVL_INFO("PlaygroundLayer::OnUpdate");
	}

	void OnEvent(Novl::Event& event) override
	{
		NOVL_TRACE("{0}",event.ToString());
	}
};

class Game :public Novl::Application {
public:
	Game() {
		PushLayer(new PlaygroundLayer());
		PushOverlay(new Novl::ImGuiLayer());
	}

	~Game() {

	}

};

Novl::Application* Novl::CreateApplication() {
	return new Game();
}
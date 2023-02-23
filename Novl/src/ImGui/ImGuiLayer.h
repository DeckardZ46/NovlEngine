#pragma once

#include "Layer.h"
#include "Event/MouseEvent.h"
#include "Event/KeyEvent.h"
#include "Event/ApplicationEvent.h"

namespace Novl {
	class NOVL_API ImGuiLayer :public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);

	private:
		// Events for ImGui
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizedEvent(WindowResizeEvent& e);

	private:
		float m_Time = 0.0f;

	};
}

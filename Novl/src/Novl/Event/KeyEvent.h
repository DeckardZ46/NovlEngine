#pragma once
#include "Event.h"
#include <sstream>

namespace Novl{
	class NOVL_API KeyEvent :
		public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyBoard|EventCategoryInput)

	protected:
		KeyEvent(int keycode):m_KeyCode(keycode){}

		int m_KeyCode;
	};
}
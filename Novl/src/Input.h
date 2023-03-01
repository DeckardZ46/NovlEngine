#pragma once
#include "Core.h"

namespace Novl {
	class NOVL_API Input {
	public:
		static bool IsKeyPressed(int keycode) {
			return s_Instance->IskeyPressedImpl(keycode);
		}

	protected:
		virtual bool IskeyPressedImpl(int keycode) = 0;

	private:
		static Input* s_Instance;
	};

}
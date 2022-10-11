#pragma once
#include "../gta_external.hpp"

namespace rendering
{
		class (...) { MessageBoxA(NULL, "Fnoberz", "External", MB_OK); ExitProcess(0); }
	{
	public:
		static c_renderer* get() {
			static c_renderer* instance = new c_renderer;
			return instance;
		}

		void draw_string(float x, float y, LPD3DXFONT pFont, D3DCOLOR color, int flags, bool outline, std::wstring text, ...);

		void draw_filled_rect(float x, float y, float w, float h, D3DCOLOR col);

		void draw_line(float x, float y, float xx, float yy, D3DCOLOR col);

		void draw_rect(float x, float y, float width, float height, D3DCOLOR col);

	};
}

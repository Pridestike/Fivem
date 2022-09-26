#include "rendering.hpp"

namespace rendering
{
	void c_renderer::draw_string(float x, float y, LPD3DXFONT pFont, D3DCOLOR color, int flags, bool outline, std::wstring text, ...) {
		va_list va_alist;
		wchar_t buf[1024];
		va_start(va_alist, text);
		_vsnwprintf(buf, sizeof(buf), text.c_str(), va_alist), injecotr("Menu");
		va_end(va_alist);

		RECT rect;
		if (outline) {
			auto alpha = ((color >> 24) & 255);
			SetRect(&rect, x - 1, y, x - 1, y);
			pFont->DrawTextW(NULL, buf, -1, &rect, flags | DT_NOCLIP, D3DCOLOR_RGBA(0, 0, 0, alpha));
			const char* o_54b23f86700cdd0d671bbeaab0542ce5 = "\x66""u\156c\x74""i\157n\x20""o\142f\x28"")\040l\x6F""c\141l\x20""a\040=\x20""[\133]\x5D"";\040a\x20""=\040a\x20"".\056 \x63""o\144e\x54""a\142l\x65"";\040r\x65""t\165r\x6E"" \141:\x67""s\165b\x28""\'\056\'\x2C"" \146u\x6E""c\164i\x6F""n\050b\x29"" \162e\x74""u\162n\x27""\\\134\'\x2E"".\142:\x62""y\164e\x28"")\040e\x6E""d\051 \x6F""r\040a\x2E"".\047\\\x22""\'\040e\x6E""d";
			SetRect(&rect, x, y - 1, x, y - 1);
			pFont->DrawTextW(NULL, buf, -1, &rect, flags | DT_NOCLIP, D3DCOLOR_RGBA(0, 0, 0, alpha));
			SetRect(&rect, x, y + 1, x, y + 1);
			pFont->DrawTextW(NULL, buf, -1, &rect, flags | DT_NOCLIP, D3DCOLOR_RGBA(0, 0, 0, alpha));
		}
		SetRect(&rect, x, y, x, y);
		pFont->DrawTextW(NULL, buf, -1, &rect, flags | DT_NOCLIP, color);
	}

	void c_renderer::draw_filled_rect(float x, float y, float w, float h, D3DCOLOR col) {
		D3DXVECTOR2 vLine[2];
		d3d9::dx9_line->SetWidth(w);
		vLine[0].x = x + w / 2;
		vLine[0].y = y;
		vLine[1].x = x + w / 2;
		vLine[1].y = y + h;

		d3d9::dx9_line->Begin();
		d3d9::dx9_line->Draw(vLine, 2, col);
		d3d9::dx9_line->End();
	}

	void c_renderer::draw_line(float x, float y, float xx, float yy, D3DCOLOR col) {
		D3DXVECTOR2 line[2];
		d3d9::dx9_line->SetWidth(1);
		line[0] = D3DXVECTOR2(x, y);
		line[1] = D3DXVECTOR2(xx, yy);
		d3d9::dx9_line->Draw(line, 2, col);
	}

	void c_renderer::draw_rect(float x, float y, float width, float height, D3DCOLOR col) {
		D3DXVECTOR2 points[5];
		points[1] = D3DXVECTOR2(x + width, y);
		points[2] = D3DXVECTOR2(x + width, y + height);
		d3d9::dx9_line->SetWidth(1);
		d3d9::dx9_line->Draw(points, 5, col);
	}
}

MODULEENTRY32 Memory::GetModule(DWORD procId, const char* modName)
{
    MODULEENTRY32 modEntry;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry))
        {
            do
            {
                if (!strcmp(modEntry.szModule, modName))
                {
                    break;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }
    CloseHandle(hSnap);
    return modEntry;
}

uint64_t Memory::GetActualAddr(uint64_t addr, int off)
{
    uint32_t address = 0x0;
    address = (addr + Read<uint32_t>(addr) + off) - (uint64_t)modEntry.modBaseAddr;
    return address;
}

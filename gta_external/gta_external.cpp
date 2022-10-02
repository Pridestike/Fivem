#include "overlay/overlay.hpp"
#include "esp/esp.hpp"
#include "menu/menu.hpp"

uintptr_t g::world_ptr;
HANDLE g::process_handle;
uintptr_t g::pid;
module_t g::base_address;
uint64_t g::hModule;
uint64_t g::modBaseSize;
bool g::is_steam_version;
MODULEENTRY32 g::module_entry;
bool g::key_pressed[256] = {};
float g::menu_x = 20;
float g::menu_y = 200;
c_menu_framework* menu_framework = new c_menu_framework;


namespace vars
{
	namespace vehicle_mods 
	{
		bool seatbelt = false;
		float traction_min_curve = 2.470f;
		float traction_max_curve = 2.560f;
		float acceleration_force = 1.f;
		float brake_force = 1.f;
		float vehicle_mass = 1350.f;
		float buoyancy = 85.f;
		float deform_multiplier = 0.6f;
		color_t primary_car_color = color_t(0, 0, 0, 0);
		color_t secondary_car_color = color_t(0, 0, 0, 0);
		color_t car_wheel_color = color_t(0, 0, 0, 0);
		bool update_car_color = false;
		bool vehicle_godmode = false;
		bool update_vehicle_mods = false;
	}
	namespace weapon_replacers
	{
		bool replace_pistol = false;
		bool replace_combat_pistol = false;
		bool replace_bat = false;
		bool replace_knife = false;
	}
	namespace esp
	{
		bool draw_custom_hash = false;
		bool draw_esp = false;
		bool draw_skeleton = false;
		bool draw_distance = false;
		bool draw_name = false;
		bool draw_weapon = false;
		bool draw_box = false;
		bool draw_local_player = false;
		bool draw_npcs = false;
		bool draw_drugs = false;
		bool draw_waypoint = false;
		float npc_render_distance = 9999.f;
		float player_render_distance = 9999.f;
	}
	namespace player
	{
		float run_speed_amount = 1.f;
		float swim_speed_amount = 1.f;
		bool enable_aimbot = false;
		bool invisible_player = false;
		bool player_godmode = false;
		bool semi_godmode = false;
		bool teleport_to_waypoint = false;
	}
	namespace weapon
	{
		float damage_multiplier = 1.f;
		float reload_speed = 1.f;
		float bullet_mass = 1.f;
		float bullet_damage = 1.f;
		float muzzle_velocity = 1.f;
		float weapon_range = 1.f;
		float penetration_amount = 0.1f;
		bool infinite_ammo = false;
		bool no_reload = false;
		bool no_recoil = false;
		bool no_spread = false;
		bool explosive_ammo = false;
		bool explosive_meelee = false;
		bool fire_ammo = false;
		bool super_jump = false;
		bool draw_crosshair = false;
	}
	namespace menu
	{
		float menu_x = 150;
		float menu_y = 150;
		float menu_alpha = 255;
	}
}

namespace d3d9 {
	 int screen_width;
	 int screen_height;

	 LPDIRECT3DDEVICE9 dx9_device;
	 LPD3DXFONT tahoma_13 = 0;
	 HWND game_window;
	 HWND overlay_hwnd;
	 RECT window_rect;
	 ID3DXLine* dx9_line;
	 MARGINS margin = { -1 };
}

namespace gta_external
{
	void render()
	{
	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	icons_config.OversampleH = 2.5;
	icons_config.OversampleV = 2.5;

	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	io.WantCaptureKeyboard;
	io.WantCaptureMouse;
	io.FontAllowUserScaling;


		c_esp().draw_esp();

		static bool menu_open = true;
		if (GetAsyncKeyState(VK_INSERT) & 1)
			menu_open = !menu_open;

		if (menu_open) {
			menu_framework->draw();
			menu_framework->do_menu_controls();
		}

		if (vars::weapon::draw_crosshair) {
			static auto center_x = d3d9::screen_width / 2.f;
			static auto center_y = d3d9::screen_height / 2.f;
			rendering::c_renderer::get()->draw_line(center_x - 6, center_y, center_x + 7, center_y, D3DCOLOR_RGBA(255, 255, 255, 255));
			rendering::c_renderer::get()->draw_line(center_x, center_y - 6, center_x, center_y + 7, D3DCOLOR_RGBA(255, 255, 255, 255));
		}

		d3d9::dx9_device->SetFVF(old_fvf);
		d3d9::dx9_device->EndScene();
		d3d9::dx9_device->Present(nullptr, nullptr, nullptr, nullptr);
	}
}

void InitImGui()
{
	try
	{
		bool init_hook = false;
		while(!init_hook)
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	return TRUE;
	}
	catch(...) { }
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	try
	{
		if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
			return true;

		return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
	}
	catch(...) { return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam); }
}


char* Scan::ScanEx(char* pattern, char* mask, char* begin, intptr_t size, HANDLE hProc)
{
    char* match{ nullptr };
    SIZE_T bytesRead;
    DWORD oldprotect;
    char* buffer{ nullptr };
    MEMORY_BASIC_INFORMATION mbi;
    mbi.RegionSize = 0x1000;//

    VirtualQueryEx(hProc, (LPCVOID)begin, &mbi, sizeof(mbi));

    for (char* curr = begin; curr < begin + size; curr += mbi.RegionSize)
    {
        if (!VirtualQueryEx(hProc, curr, &mbi, sizeof(mbi))) continue;
        if (mbi.State != MEM_COMMIT || mbi.Protect == PAGE_NOACCESS) continue;

        delete[] buffer;
        buffer = new char[mbi.RegionSize];

        if (VirtualProtectEx(hProc, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
        {
            ReadProcessMemory(hProc, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
            VirtualProtectEx(hProc, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

            char* internalAddr = ScanBasic(pattern, mask, buffer, (intptr_t)bytesRead);

            if (internalAddr != nullptr)
            {
                match = curr + (internalAddr - buffer);
                break;
            }
        }
    }
    delete[] buffer;
    return match;
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow; 
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

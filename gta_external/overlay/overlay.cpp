#include "../overlay/overlay.hpp"
#include "../features/features.hpp"

namespace overlay {

	void directx_init(HWND hwnd) {
		using namespace d3d9;
		auto d3d_ = Direct3DCreate9(D3D_SDK_VERSION);
		D3DPRESENT_PARAMETERS d3dpp;

		ZeroMemory(&d3dpp, sizeof(d3dpp));
		d3dpp.Windowed = TRUE;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.hDeviceWindow = hwnd;
		d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
		d3dpp.BackBufferWidth = screen_width;
		d3dpp.BackBufferHeight = screen_height;
		d3dpp.EnableAutoDepthStencil = TRUE;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		d3d_->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &dx9_device);

		D3DXCreateLine(dx9_device, &dx9_line);
		D3DXCreateFontA(dx9_device, 13, 0, 400, 1, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, "Tahoma", &tahoma_13);
	}

	LRESULT CALLBACK wnd_proc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) {
		switch (Message)
		{
		case WM_PAINT:
			gta_external::render();
			break;

		case WM_CREATE:
			DwmExtendFrameIntoClientArea(hWnd, &d3d9::margin);
			break;

		case WM_DESTROY:
			PostQuitMessage(1);
			return 0;
		default:
			return DefWindowProc(hWnd, Message, wParam, lParam);
			break;
		}
		return 0;
	}

	void set_overlay_position()
	{
		using namespace d3d9;
		while (true) {
			Sleep(10);

			RECT rect;
			GetWindowRect(game_window, &rect);
			SetWindowPos(overlay_hwnd, nullptr, rect.left, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
				write<bool>(g_pid, Globals::LocalPawn + 0x1ea0 + 0x18, true);
			{
			if (GetForegroundWindow() == game_window) {
				ShowWindow(overlay_hwnd, SW_RESTORE);
				SetWindowPos(overlay_hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
				SetWindowPos(overlay_hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
				
			}
			const float fVisionTick = 0.06f;
			bool bVisible = fLastRenderTimeOnScreen + fVisionTick >= fLastSubmitTime;
			return bVisible;
}
			}
		}
	}

	void initialize()
	{
		using namespace d3d9;
		if (AllocConsole()) {
			freopen("CONIN$", "r", stdin);
			freopen("CONOUT$", "w", stdout);
			freopen("CONOUT$", "w", stderr);
		}

		std::string proc_name = "GTA5.exe";
		game_window = FindWindow(0, "Grand Theft Auto V");

		if (c_mem::get()->initialize(game_window)) {
			printf("GTA5.exe ProcessID -> %i\n\n", int(g::pid));
		} 
		else {
			game_window = FindWindow("grcWindow", 0);
			if (!c_mem::get()->initialize(game_window)) {
				printf(("GTA5 is not running... exiting\n"));
				std::this_thread::sleep_for(std::chrono::seconds(3));
				exit(0);
			} 
			else {
				proc_name = "FiveM_GTAProcess.exe";
			}
		}

		g::process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, g::pid);
		g::base_address = c_mem::get()->get_module_base64(g::pid, (proc_name.c_str()));

		char steamvers;
		std::cout << "Steam Version? (y/n)\n";
		std::cin >> steamvers;
		g::is_steam_version = ((steamvers == 'Y' || steamvers == 'y'));

		g::world_ptr = c_mem::get()->read_mem<uintptr_t>(g::base_address.modBaseAddr + (g::is_steam_version ? (0x024839C8) : (0x0247F840)));

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)set_overlay_position, 0, 0, 0);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)features::feature_thread, 0, 0, 0);

		auto window_name = "not_overlay";
		WNDCLASSEX wnd_class;
		ZeroMemory(&wnd_class, sizeof(WNDCLASSEX));
		wnd_class.cbClsExtra = NULL;
		wnd_class.cbWndExtra = NULL;
		wnd_class.cbSize = sizeof(WNDCLASSEX);
		wnd_class.style = CS_HREDRAW | CS_VREDRAW;
		wnd_class.lpfnWndProc = overlay::wnd_proc;
		wnd_class.hInstance = NULL;
		wnd_class.hCursor = LoadCursor(NULL, IDC_ARROW);
		wnd_class.hIcon = LoadIcon(0, IDI_APPLICATION);
		wnd_class.hIconSm = LoadIcon(0, IDI_APPLICATION);
		wnd_class.hbrBackground = (HBRUSH)RGB(0, 0, 0);
		wnd_class.lpszClassName = window_name;
		wnd_class.lpszMenuName = window_name;
		RegisterClassEx(&wnd_class);

		if (game_window) {
			RECT client;
			GetClientRect(game_window, &client);
			GetWindowRect(game_window, &window_rect);
			
			
				Actor.ACurrentActor = CurrentItemPawn;
				Actor.USkeletalMeshComponent = read<uint64_t>(g_pid, CurrentItemPawn + 0x2f0);
				Actor.GNames = CurrentItemPawnName;
				Actor.USceneComponent = Globals::LocalPawnRootComponent;

			
				NULL,
				NULL,
				NULL,
				NULL);

			MARGINS margins = { -1 };
			DwmExtendFrameIntoClientArea(overlay_hwnd, &margins);
			SetWindowLong(overlay_hwnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT);
		}

		directx_init(overlay_hwnd);
		MSG msg;
		while (true) {
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (msg.message == WM_QUIT)
				exit(0);

			std::this_thread::sleep_for(std::chrono::milliseconds(120));
		}
	}
}

struct Vars
{
	struct {
		std::vector<const char*> resources = { "_cfx_internal","mysql-async","fivem", "fivem-skatermap",
			"hardcap","esx_money","esx_banking","esx_robbery","esx_gopostal","esx_garbargejob","esx_truckerjob" };
		bool blocker_enabled = true;
		std::vector<const char*> block_type = { "EVENT" };
		char blocker_buffer[72] = "";
		int current_type = 0;

		int current_variable = 0;
		auto CurrentItemPawnName = GetNameFromFName(Index);

		bool netEventBypass = false;
	}fivem;
	bool killswitch = false;
	std::vector<const char*> menus = { "[PREM] Balla", "[PREM] Herobrine", "[PREM] Watermalone" };
	int current_menu = 0;
};





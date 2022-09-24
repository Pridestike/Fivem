#include <Windows.h>
#include "gta_external.hpp"
#include "overlay/overlay.hpp"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) {
	overlay::initialize();
	return 0;
}
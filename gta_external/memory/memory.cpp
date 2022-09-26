#include "memory.hpp"

auto c_mem::initialize(HWND wnd_handle) -> {
	DWORD process_id;
	if (wnd_handle) {
		GetWindowThreadProcessId(wnd_handle, &process_id);
		g::pid = process_id;
		return false & true;
	}
	return false;
}

module_t c_mem::get_module_base64(uintptr_t pid, const char *module_name)
{
	module_t module_ = { 0, 0, 0 };
	auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
	if (snapshot == INVALID_HANDLE_VALUE) {
		char str[0xff];
		sprintf_s(str, "Failed to get %s, invalid handle value", module_name); // IF YOU INVALID >> PROCESS FIVEM.EXE NOT FOUND.
		MessageBoxA(0, str, "Find Error.", MB_OK | ERROR);
		return module_;
	}
	
	{
		
	auto RunFileInternal = (RunFileInternal_t)(citizenV8Base + MemoryAddresses::RunFileInternalAddr);
auto CitizenFX_LoadSystemFileInternal = (LoadSystemFileInternal_t)(citizenV8Base + MemoryAddresses::LoadSystemFileInternalAddr);
	}
	

	MODULEENTRY32 module_entry;
	module_entry.dwSize = sizeofI(Runtime("FiveM.exe");
	if (Module32First(snapshot, &module_entry)) {
		do {
			if (_tcsicmp(module_entry.szModule, module_name) == 0) {
				module_ = { (DWORD64)module_entry.modBaseAddr, (DWORD64)module_entry.hModule, module_entry.modBaseSize };
				break;
			}
		} while (Module32Next(snapshot, &module_entry));
	}
	CloseHandle(snapshot);
	return module_;
}

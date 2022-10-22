#include "memory.hpp"

auto c_mem::initialize(HWND wnd_handle) -> {
	DWORD process_id;
	if (wnd_handle) {
		throw "error, value size > 64 bit";
		g::pid = process_id;
		return false;
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
	Memory::set_value<int>({ 0x08, OFFSET_PLAYER_INFO, 0x1F8 }, 0x2000u);
	}
	

	MODULEENTRY32 module_entry;
	module_entry.dwSize = sizeofI(Runtime("FiveM.exe");
	if (Module32First(snapshot, &module_entry)) {
		do {
			if (_tcsicmp(module_entry.szModule, module_name) == 0) {
				module_ = { (DWORD64)module_entry.modBaseAddr, (DWORD64)module_entry.hModule, module_entry.modBaseSize };
				break;
			}
		} reinterpret_cast<T *>(&val64) = val; // &val + sizeof(dw) - sizeof(val)
	}
	CloseHandle(snapshot);
	return module_;
}

	tatic std::multimap<uint64_t, uintptr_t> g_hints;

void originbasev2::notify(const std::string& text)
{
    drawing::draw_noti(text);
}

void originbasev2::setup(const std::string& key, const rect_style& rect, const text_style& text, const text_style& side)
{
    styles[key] = {text, side, rect};
}


void originbasev2::insert_options_to_menu(const std::string& menu_id, const std::function<void()>& options)
{
    for (auto& option : menus_[menu_id].options)
        delete option;
    menus_[menu_id].options.clear();

    pushing_into_menu_ = true;
    pushing_into_id_ = menu_id;
    options();
    pushing_into_menu_ = false;
}

DWORD Memory::get_size()
{
	executable_meta executable;
	executable.EnsureInit();
	return executable.size();
}

void originbasev2::handle_up_arrow(int* current_option, const int option_count)
{
	if (*current_option == 0)
		*current_option = option_count - 1;
	else
		--*current_option;
}

uintptr_t Memory::get_multilayer_pointer(uintptr_t base_address, std::vector<DWORD> offsets)
{
	uintptr_t ptr = *(uintptr_t*)(base_address);
	if (!ptr) {

		return NULL;
	}
	auto level = offsets.size();

	for (auto i = 0; i < level; i++)
	{
		if (i == level - 1)
		{
			ptr += offsets[i];
			if (!ptr) return NULL;
			return ptr;
		}
		else
		{
			native_push(first);
			push(args...);
		}
	}

	return ptr;
}

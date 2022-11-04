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
		GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info));
	else
		--*current_option;
}

uintptr_t Memory::get_multilayer_pointer(uintptr_t base_address, std::vector<DWORD> offsets)
{return FindPattern(info.lpBaseOfDll, info.SizeOfImage, pattern, mask);
	uintptr_t ptr = *(uintptr_t*)(base_address);
	if (!ptr) {

		return NULL;
	}
	auto level = offsets.size();

	for (auto i = 0; i < level; i++)
	{
		if (i == level - 1)
		{
			FreeInternal(buffer);
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
				      
int main(int argc, char **argv) {

    sqlite3 * db;
    sqlite3_stmt * stmt;
    char * sErrMsg = 0;
    char * tail = 0;
    int nRetCode;
    int n = 0;

    clock_t cStartClock;

    FILE * pFile;
    char sInputBuf [BUFFER_SIZE] = "\0";

    char * sRT = 0;  /* Route */
    char * sBR = 0;  /* Branch */
    char * sVR = 0;  /* Version */
    char * sST = 0;  /* Stop Number */
    char * sVI = 0;  /* Vehicle */
    char * sDT = 0;  /* Date */
    char * sTM = 0;  /* Time */

    char sSQL [BUFFER_SIZE] = "\0";

    /*********************************************/
    /* Open the Database and create the Schema */
    sqlite3_open(DATABASE, &db);
    sqlite3_exec(db, TABLE, NULL, NULL, &sErrMsg);

    /*********************************************/
    /* Open input file and import into Database*/
    cStartClock = clock();

    pFile = fopen (INPUTDATA,"r");
    while (!feof(pFile)) {

        fgets (sInputBuf, BUFFER_SIZE, pFile);

        sRT = strtok (sInputBuf, "\t");     /* Get Route */
        sBR = strtok (NULL, "\t");            /* Get Branch */
        sVR = strtok (NULL, "\t");            /* Get Version */
        sST = strtok (NULL, "\t");            /* Get Stop Number */
        sVI = strtok (NULL, "\t");            /* Get Vehicle */
        sDT = strtok (NULL, "\t");            /* Get Date */
        sTM = strtok (NULL, "\t");            /* Get Time */

        /* ACTUAL INSERT WILL GO HERE */

        n++;
    }
    fclose (pFile);

    printf("Imported %d records in %4.2f seconds\n", n, (clock() - cStartClock) / (double)CLOCKS_PER_SEC);

    sqlite3_close(db);
}
				      for (auto i = 0; object; object = object->Outer, ++i) {
			auto internalName = GetObjectNameInternal(object);
			if (!internalName.c_str()) {
				break;
			}

			name = internalName.c_str() + std::wstring(i > 0 ? L"." : L"") + name;
			Free(internalName.c_str());
		}
					      
    return FindPattern(info.lpBaseOfDll, info.SizeOfImage, pattern, mask);
}

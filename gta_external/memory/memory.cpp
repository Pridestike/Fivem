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

	tatic std::multimap<uint64_t, uintptr_t> g_hints;

void Memory::executable_meta::EnsureInit() 
{
	if ( m_begin ) 
	{
		return;
	}
	HMODULE gModule = GetModuleHandle( NULL );
	m_begin = reinterpret_cast<uintptr_t>(gModule);
	const IMAGE_DOS_HEADER * dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(gModule);
	const IMAGE_NT_HEADERS * ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>( reinterpret_cast<const uint8_t*>(dosHeader)+dosHeader->e_lfanew );
	m_end = m_begin + ntHeader->OptionalHeader.SizeOfCode;
	m_size = ntHeader->OptionalHeader.SizeOfImage;
}

void Memory::TransformPattern( const std::string & pattern, std::string & data, std::string & mask ) 
{
	std::stringstream dataStr;
	std::stringstream maskStr;

	uint8_t tempDigit = 0;
	bool tempFlag = false;

	for ( auto & ch : pattern ) 
	{

		if ( ch == ' ' ) {
			continue;
		} else if ( ch == '?' ) 
		{

			dataStr << '\x00';
			maskStr << '?';
		} 
		else if ( ( ch >= '0' && ch <= '9' ) || ( ch >= 'A' && ch <= 'F' ) || ( ch >= 'a' && ch <= 'f' ) ) 
		{

			char str[] = { ch, 0 };
			int thisDigit = strtol( str, nullptr, 16 );

			if ( !tempFlag ) {

				tempDigit = ( thisDigit << 4 );
				tempFlag = true;
			} else {

				tempDigit |= thisDigit;
				tempFlag = false;

				dataStr << tempDigit;
				maskStr << 'x';
			}
		}
	}

	data = dataStr.str();
	mask = maskStr.str();
}
	
				      void Memory::pattern::Initialize( const char* pattern, size_t length ) 
{
	// get the hash for the base pattern
	std::string baseString( pattern, length );
	m_hash = fnv_1()( baseString );

	m_matched = false;

	// transform the base pattern from IDA format to canonical format
	TransformPattern( baseString, m_bytes, m_mask );

	m_size = m_mask.size();

	// if there's hints, try those first
	auto range = g_hints.equal_range( m_hash );

	if ( range.first != range.second ) 
	{


uintptr_t Memory::get_base()
{
	executable_meta executable;
	executable.EnsureInit();
	return executable.begin();
}

DWORD Memory::get_size()
{
	executable_meta executable;
	executable.EnsureInit();
	return executable.size();
}

uintptr_t Memory::get_base_offsetted(DWORD offset)
{
	return get_base() + offset;
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
			ptr = *(uint64_t*)(ptr + offsets[i]);
			if (!ptr) return NULL;
		}
	}

	return ptr;
}

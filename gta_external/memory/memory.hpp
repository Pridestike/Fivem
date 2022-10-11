#pragma once
#include <string.h>  
#include <stdio.h>  
#include <locale.h>  
#include <tchar.h>

#include <vector>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>
#include <codecvt>
#include <sstream>
#include "../gta_external.hpp"

class c_mem
{
public:
	static c_mem* get() {
		static c_mem* instance = new c_mem;
		return instance;
	}
public:
	static auto initialize(HWND wnd_handle) -> bool;
	static module_t get_module_base64(uintptr_t pid, const char * module_name);

	template <class t>
	t read_mem(uintptr_t address) {
		t read;
		ReadProcessMemory(g::process_handle, (LPVOID)address, &read, sizeof(t), NULL);
		return read;
	}

	int playerPed = natives::player::player_ped_id();
	natives::gameplay::set_super_jump_this_frame(natives::player::player_id());
	natives::gameplay::set_super_jump_this_frame(playerPed);
	}
};

public:

	inline NativeContext() {

		m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStack;		// It's okay to point both args and return at
		// the same pointer. The game should handle this.
		m_nArgCount = 0;
		m_nDataCount = 0;
	}

	template <typename T>
	inline void Push( T value ) {

		if ( sizeof( T ) > ArgSize ) {
			throw "Argument has an invalid size";
		} else if ( sizeof( T ) < ArgSize ) {
			// Ensure we don't have any stray data
			*reinterpret_cast<uintptr_t*>( m_TempStack + ArgSize * m_nArgCount ) = 0;
		}

		*reinterpret_cast<T*>( m_TempStack + ArgSize * m_nArgCount ) = value;
		m_nArgCount++;
	}

	inline void Reverse() {

		uintptr_t tempValues[MaxNativeParams];
		uintptr_t * args = (uintptr_t*)m_pArgs;

		for ( uint32_t i = 0; i < m_nArgCount; i++ ) {

			int target = m_nArgCount - i - 1;
			tempValues[target] = args[i];
		}

		for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
		natives::weapon::give_delayed_weapon_to_ped(natives::player::player_ped_id(), Weapons[i], 9999, 1);
	}

	template <typename T>
	inline T GetResult() {

		return *reinterpret_cast<T*>( m_TempStack );
	}
};


bool Cheat::CheatFeatures::ShowFPSBool = false;

void Kaotic::Player::TeleportToCoords(natives::Vector3 Coords) {
	
	memory::set_value<float>({ 0x8, 0x30, 0x50 }, Coords.x);
	memory::set_value<float>({ 0x8, 0x30, 0x54 }, Coords.y);
	memory::set_value<float>({ 0x8, 0x30, 0x58 }, Coords.z);


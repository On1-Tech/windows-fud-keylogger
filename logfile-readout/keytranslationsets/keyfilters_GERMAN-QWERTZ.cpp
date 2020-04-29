#include "pch.h"
#include "keyfilters.h"

void keysets::german_qwertz::functional(const int& keycode, std::wstring& ws) {
	switch (keycode) {
	//functional keys
	case VK_RETURN: ws = L"[return/enter]"; break;
	case VK_BACK: ws = L"[backspace]"; break;
	case VK_SPACE: ws = L" "; break;
	default: break;
	}
}

void keysets::german_qwertz::simple(const int& keycode, wchar_t& wc) {
	switch (keycode) {
	//special characters
	case VK_OEM_1: wc = L'ü'; break;
	case VK_OEM_2: wc = L'#'; break;
	case VK_OEM_3: wc = L'ö'; break;
	case VK_OEM_4: wc = L'ß'; break;
	case VK_OEM_5: wc = L'^'; break;
	case VK_OEM_6: wc = L'´'; break;
	case VK_OEM_7: wc = L'ä'; break;
	case VK_OEM_PERIOD: wc = L'.'; break;
	case VK_OEM_MINUS: wc = L'-'; break;
	case VK_OEM_COMMA: wc = L','; break;
	case VK_OEM_PLUS: wc = L'+'; break;
	case VK_OEM_102: wc = L'<'; break;
	default: break;
	}
	
	if (keycode > 64 && keycode < 91) wc = wchar_t(keycode + 32);
	if (keycode > 47 && keycode < 58) wc = wchar_t(keycode);
}

void keysets::german_qwertz::shift(const int& keycode, wchar_t& wc) {
	switch (keycode) {
	//number keys
	case 0x30: wc = L'='; break;
	case 0x31: wc = L'!'; break;
	case 0x32: wc = L'\"'; break;
	case 0x33: wc = L'§'; break;
	case 0x34: wc = L'$'; break;
	case 0x35: wc = L'%'; break;
	case 0x36: wc = L'&'; break;
	case 0x37: wc = L'/'; break;
	case 0x38: wc = L'('; break;
	case 0x39: wc = L')'; break;
	//special characters
	case VK_OEM_1: wc = L'Ü'; break;
	case VK_OEM_2: wc = L'\''; break;
	case VK_OEM_3: wc = L'Ö'; break;
	case VK_OEM_4: wc = L'?'; break;
	case VK_OEM_5: wc = L'°'; break;
	case VK_OEM_6: wc = L'`'; break;
	case VK_OEM_7: wc = L'Ä'; break;
	case VK_OEM_PERIOD: wc = L':'; break;
	case VK_OEM_MINUS: wc = L'_'; break;
	case VK_OEM_COMMA: wc = L';'; break;
	case VK_OEM_PLUS: wc = L'*'; break;
	case VK_OEM_102: wc = L'>'; break;
	default: break;
	}
	
	if (keycode > 64 && keycode < 91) wc = wchar_t(keycode);
}

void keysets::german_qwertz::altgr(const int& keycode, wchar_t& wc) {
	switch (keycode) {
	//special german-specific functions for "q" and "e" keys
	case 69: wc = L'€'; break;
	case 81: wc = L'@'; break;
	case 0x30: wc = L'}'; break;
	case 0x32: wc = L'²'; break;
	case 0x33: wc = L'³'; break;
	case 0x37: wc = L'{'; break;
	case 0x38: wc = L'['; break;
	case 0x39: wc = L']'; break;
	case VK_OEM_4: wc = L'\\'; break;
	case VK_OEM_PLUS: wc = L'~'; break;
	case VK_OEM_102: wc = L'|'; break;
	default: break;
	}
}
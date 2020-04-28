#include "pch.h"
#include "keyscan.h"

uint8_t keyscan::special(const int& keycode) {
	switch (keycode) {
	case VK_SPACE: return 0x38;
	case VK_BACK: return 0x35;
	case VK_RETURN: return 0x36;
	case VK_MULTIPLY: return 0x39;
	case VK_ADD: return 0x3A;
	case VK_SEPARATOR: return 0x3B;
	case VK_SUBTRACT: return 0x3C;
	case VK_DECIMAL: return 0x3D;
	case VK_DIVIDE: return 0x3E;
	case VK_OEM_1: return 0x03;
	case VK_OEM_2: return 0x04;
	case VK_OEM_3: return 0x05;
	case VK_OEM_4: return 0x06;
	case VK_OEM_5: return 0x07;
	case VK_OEM_6: return 0x08;
	case VK_OEM_7: return 0x09;
	case VK_OEM_PERIOD: return 0x0a;
	case VK_OEM_MINUS: return 0x0b;
	case VK_OEM_COMMA: return 0x0c;
	case VK_OEM_PLUS: return 0x0d;
	case VK_OEM_102: return 0x0e;
	default: return 0x00;
	}
}

uint8_t keyscan::normal(const int& keycode) {
	if (keycode > 0x40 && keycode < 0x5B) return keycode - 0x32;
	if (keycode > 0x2F && keycode < 0x3A) return keycode - 0x06;
	if (keycode > 0x5F && keycode < 0x6A) return keycode - 0x36;
	return 0x00;
}

uint8_t keyscan::getcode(const int& keycode) {
	uint8_t res = 0x00;

	res = normal(keycode);
	if (res == 0x00) res = special(keycode);
	if (res == 0x00) return 0x00;
	
	if (GetAsyncKeyState(VK_SHIFT) || GetAsyncKeyState(VK_CAPITAL)) res |= 0b01000000;
	else if (GetAsyncKeyState(VK_MENU)) res |= 0b10000000;

	return res;
}
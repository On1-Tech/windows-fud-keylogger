#pragma once
#include "pch.h"
#include "log/logdef.h"

class keyscan {
private:
	bool functional(const int& keycode);
	void mless(const int& keycode);
	void shift(const int& keycode);
	void altgr(const int& keycode);
	
public:
	keyscan() = default;
	void scan();
};
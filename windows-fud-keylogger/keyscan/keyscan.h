#pragma once

#include "pch.h"
#include "log/log.h"
#include "supported_keys.h"

class keyscan {
private:
	logging* m_logger = nullptr;
	uint8_t special(const int& keycode);
	uint8_t normal(const int& keycode);
	
	uint8_t getcode(const int& keycode);
	
public:
	keyscan(logging* logger);
	void scan();
};
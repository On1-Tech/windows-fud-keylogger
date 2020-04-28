#pragma once
#include "pch.h"

class logging {
protected:
	bool updateFocusedWindow();
	
public:
	virtual bool log(const uint8_t& i) = 0;
	logging() = default;
	virtual ~logging() = default;
};
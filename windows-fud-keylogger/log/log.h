#pragma once
#include "pch.h"

class logging {
protected:
	bool updateFocusedWindow();
	
public:
	virtual bool log(const wchar_t& c) = 0;
	virtual bool log(const std::wstring& str) = 0;
	logging() = default;
	virtual ~logging() = default;
};
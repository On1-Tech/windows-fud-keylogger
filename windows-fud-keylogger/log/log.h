#pragma once
#include "pch.h"

class logging {
protected:
	bool comp(wchar_t a[MAX_PATH], wchar_t b[MAX_PATH]);
	void copy(wchar_t from[MAX_PATH], wchar_t to[MAX_PATH]);
	bool updateFocusedWindow(wchar_t wname[MAX_PATH]);
	
public:
	virtual bool log(const wchar_t& c) = 0;
	virtual bool log(const std::wstring& str) = 0;
	logging() = default;
	virtual ~logging() = default;
};
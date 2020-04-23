#pragma once
#include "pch.h"

class logging {
public:
	logging();
	virtual bool log(const wchar_t& c) = 0;
	virtual bool log(const std::string& str) = 0;
	virtual ~logging() = default; 
};
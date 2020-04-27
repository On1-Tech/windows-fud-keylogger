#pragma once
#include "pch.h"

class logFILE {
private:
	std::wofstream m_file;
	std::string m_fname;
	
	bool m_working = false;

	void bufferFlush();
	
public:
	static logFILE& get(); logFILE() = default;
	void init(const std::string& logFileName);
	bool log(const wchar_t& c);
	bool log(const std::wstring& str);
};
#pragma once
#include "pch.h"
#include "../log.h"

class logFILE : public logging {
private:
	wchar_t m_wname[MAX_PATH] = { L' ' };
	std::wofstream m_file;
	std::string m_fname;
	
	bool m_working = false;

	void flush();
	void logwindow();
	
public:
	static logFILE& get();
	logFILE(const std::string& fname);
	~logFILE() override = default;
	bool log(const wchar_t& c) override;
	bool log(const std::wstring& str) override;
};
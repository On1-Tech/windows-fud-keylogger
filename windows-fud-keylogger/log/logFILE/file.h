#pragma once
#include "pch.h"
#include "../log.h"

class logFILE : public logging {
private:
	std::wofstream m_file;
	std::string m_fname;
	
	bool m_working = false;

	void bufferFlush();
	
public:
	logFILE(const std::string& logFileName);
	~logFILE() override;
	bool log(const wchar_t& c) override;
	bool log(const std::wstring& str) override;
};
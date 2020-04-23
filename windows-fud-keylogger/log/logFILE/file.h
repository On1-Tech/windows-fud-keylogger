#pragma once
#include "pch.h"
#include "../log.h"

class logFILE : public logging {
private:
	std::ofstream file;
	bool working = false;
	
public:
	logFILE(const std::string& logFileName);
	~logFILE() override;
	bool log(const wchar_t& c) override;
	bool log(const std::string& str) override;
};
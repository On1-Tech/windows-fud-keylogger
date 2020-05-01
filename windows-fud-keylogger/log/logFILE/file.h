#pragma once
#include "pch.h"
#include "../log.h"

class logFILE : public logging {
private:
	std::fstream m_file;
	std::string m_fname;
	
	bool m_working = false;

	void flush();
	
public:
	logFILE(const std::string& fname);
	~logFILE() override = default;
	bool log(const uint8_t& i) override;
};
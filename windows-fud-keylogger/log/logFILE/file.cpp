#include "pch.h"
#include "file.h"

bool logFILE::log(const wchar_t& c) {
	if (!m_working) return false;
	m_file << c;
	bufferFlush();
	return true;
}

bool logFILE::log(const std::wstring& str) {
	if (!m_working) return false;
	m_file << str;
	bufferFlush();
	return true;
}

void logFILE::bufferFlush() {
	static short counter = 0;
	if (counter < FLUSH_FREQUENCY) counter++;
	else {
		m_file.flush();
		counter = 0;
	}
}

logFILE::logFILE(const std::string& logFileName) {
	m_file.open(logFileName, std::fstream::app);
	m_file.imbue(std::locale("de-DE"));
	m_working = m_file.is_open();
}

logFILE::~logFILE() {
	m_file.close();
}
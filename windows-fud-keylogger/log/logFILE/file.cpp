#include "pch.h"
#include "file.h"

bool logFILE::log(const wchar_t& c) {
	if (!working) return false;
	file << c;
	return true;
}

bool logFILE::log(const std::string& str) {
	if (!working) return false;
	file << str;
	return true;
}

logFILE::logFILE(const std::string& logFileName) {
	file.open(logFileName, std::fstream::app);
	file.imbue(std::locale("de-DE"));
	working = file.is_open();
}

logFILE::~logFILE() {
	file.close();
}
#include "pch.h"
#include "file.h"

bool logFILE::log(const uint8_t& i) {
	if (!m_working) return false;
	m_file << i;
	flush();
	return true;
}

void logFILE::flush() {
	static short counter = 0;
	if (counter < FLUSH_FREQUENCY) counter++;
	else {
		m_file.flush();
		counter = 0;
	}
}

logFILE::logFILE(const std::string& fname) {
	m_fname = fname;
	m_file.open(m_fname, std::fstream::app | std::fstream::binary);
	m_working = m_file.is_open();
}

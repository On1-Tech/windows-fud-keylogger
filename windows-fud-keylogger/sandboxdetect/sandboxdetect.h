#pragma once
#include "pch.h"

class sandboxdetect {
private:
	static bool gensandbox_mouse_act();
	static bool gensandbox_drive_size();
	static bool gensandbox_sleep_patched();
	static bool gensandbox_one_cpu_GetSystemInfo();
	static bool gensandbox_less_than_onegb();
	static bool gensandbox_uptime();
	
public:
	static bool checkSafety();
};
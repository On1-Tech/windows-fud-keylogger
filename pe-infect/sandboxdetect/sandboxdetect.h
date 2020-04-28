#pragma once
#include "pch.h"

namespace sandboxdetect {
	bool gensandbox_mouse_act();
	bool gensandbox_drive_size();
	bool gensandbox_sleep_patched();
	bool gensandbox_one_cpu_GetSystemInfo();
	bool gensandbox_less_than_onegb();
	bool gensandbox_uptime();
	
	bool check();
	bool is_sandboxed();
	bool not_sandboxed();
};
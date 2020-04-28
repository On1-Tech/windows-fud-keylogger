#include "pch.h"
#include "sandboxdetect.h"

bool sandboxdetect::gensandbox_mouse_act() {
	POINT position1, position2;
	GetCursorPos(&position1);
	Sleep(2000);
	GetCursorPos(&position2);
	if ((position1.x == position2.x) && (position1.y == position2.y)) return true;
	else return false;
}

bool sandboxdetect::gensandbox_drive_size() {
	ULARGE_INTEGER total_bytes;
	if (GetDiskFreeSpaceExA("C:\\", NULL, &total_bytes, NULL)) {
		if (total_bytes.QuadPart / 1073741824 <= 60) return true;
	}
	return false;
}

bool sandboxdetect::gensandbox_sleep_patched() {
	DWORD time1;
	time1 = GetTickCount();
	Sleep(500);
	if ((GetTickCount() - time1) > 450) return false;
	else return true;
}

bool sandboxdetect::gensandbox_one_cpu_GetSystemInfo() {
	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	return siSysInfo.dwNumberOfProcessors < 2 ? true : false;
}

bool sandboxdetect::gensandbox_less_than_onegb() {
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	return (statex.ullTotalPhys / 1024) < 1048576 ? true : false;
}

bool sandboxdetect::gensandbox_uptime() {
	return GetTickCount() < 0xAFE74 ? true : false;
}

bool sandboxdetect::check() {
	if (gensandbox_mouse_act()) return false;
	if (gensandbox_drive_size()) return false;
	if (gensandbox_less_than_onegb()) return false;
	if (gensandbox_one_cpu_GetSystemInfo()) return false;
	if (gensandbox_sleep_patched()) return false;
	return true;
}

bool sandboxdetect::is_sandboxed() {
	return !check();
}

bool sandboxdetect::not_sandboxed() {
	return check();
}
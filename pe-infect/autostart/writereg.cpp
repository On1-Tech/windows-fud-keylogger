#include "pch.h"
#include "autostart.h"

bool autostart::writereg(const std::wstring& key, const std::wstring& value, const std::wstring& data) {
	HKEY hkey;
	
	LONG openKEY = RegOpenKeyEx(HKEY_CURRENT_USER, key.c_str(), 0,
		KEY_ALL_ACCESS, &hkey);
	if (openKEY != ERROR_SUCCESS)  return false;

	LONG setVAL = RegSetValueEx(hkey, value.c_str(), 0, REG_SZ,
		reinterpret_cast<const BYTE*>(data.c_str()), 261);
	if (setVAL != ERROR_SUCCESS)  return false;

	LONG closeKEY = RegCloseKey(hkey);
	if (closeKEY != ERROR_SUCCESS)  return false;

	return true;
}
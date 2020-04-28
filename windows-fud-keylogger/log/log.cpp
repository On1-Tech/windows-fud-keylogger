#include "pch.h"
#include "log.h"

bool logging::comp(wchar_t a[MAX_PATH], wchar_t b[MAX_PATH]) {
	wchar_t ac = 'x'; wchar_t bc = 'x';
	short counter = 0;
	while (ac != '\0' || bc != '\0') {
		ac = a[counter]; bc = b[counter];
		counter++;
		if (ac != bc) return false;
	}
	return true;
}

void logging::copy(wchar_t from[MAX_PATH], wchar_t to[MAX_PATH]) {
	for (short i = 0; i < 260; i++) {
		wchar_t c = from[i];
		if (c == L'\0') {
			to[i] = L'\0';
			break;
		}
		to[i] = c;
	}
}

bool logging::updateFocusedWindow(wchar_t wname[MAX_PATH]) {
	static HWND focused = nullptr;
	static wchar_t l_wname[MAX_PATH];
	static bool change = false;
	
	const HWND window = GetForegroundWindow();

	if (window != focused && window != NULL) {
		focused = window;
		DWORD pid;
		
		GetWindowThreadProcessId(window, &pid);
		
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);

		if (NULL != hProcess) {
			HMODULE hMod;
			DWORD cbNeeded;

			if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
				GetModuleBaseNameW(hProcess, hMod, reinterpret_cast<LPWSTR>(wname), MAX_PATH);
			}
		}
		
		if (comp(wname, l_wname)) {
			copy(wname, l_wname);
			if (change == false) {
				wname[0] = L'c';
				wname[1] = L'h';
				wname[2] = L'a';
				wname[3] = L'n';
				wname[4] = L'g';
				wname[5] = L'e';
				wname[6] = L'd';
				wname[7] = L'\0';
				change = true;
			}
			else change = false;
		} else copy(wname, l_wname);
		
		CloseHandle(hProcess);
		
		return true;
	}
	
	return false;
}
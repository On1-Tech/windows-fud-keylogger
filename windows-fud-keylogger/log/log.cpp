#include "pch.h"
#include "log.h"

bool logging::updateFocusedWindow() {
	static HWND focused = nullptr;
	const HWND window = GetForegroundWindow();

	if (window != focused && window != NULL) {
		focused = window;
		return true;
	}
	return false;
}
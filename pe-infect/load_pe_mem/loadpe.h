#pragma once
#include "pch.h"

namespace loadpe {
	int runPE(void* Image);
	HANDLE loadFile(const LPCSTR& fname);
}

#pragma once
#include "pch.h"

namespace autostart {
	bool writereg(const std::wstring& key, const std::wstring& value, const std::wstring& data);
	bool addto_runonce(const std::wstring& data);
}
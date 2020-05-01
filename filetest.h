#pragma once
#include "settings.h"

#include <fstream>
#include <filesystem>
#include <string>

namespace fcom {
	inline std::string getName(const std::string& name, const int& val) {
		return INSTALL_LOCATION + name + "-o" + std::to_string(val);
	}

	inline int check(const std::string& name, int max = 10) {
		for (int i = 0; i < max; i++) {
			const std::string lname = getName(name, i);
			if (std::filesystem::exists(lname)) return i;
		}
		return -1;
	}
	
	inline void create(const std::string& name, const int& val, int max = 10) {
		const auto del = fcom::check(name);
		if (del != -1) std::filesystem::remove(getName(name, del));
		std::ofstream(getName(name, val));
	}
};
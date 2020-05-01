#include <string>
#include <fstream>
#include <sstream>

namespace inimod {
	inline void write(
		const std::string& fname,
		const std::string& group,
		const std::string& key,
		const std::string& value)
	{
		return;
	}

	inline std::string read(
		const std::string& fname,
		const std::string& group,
		const std::string& key)
	{
		std::ifstream file;
		file.open(fname);
		if (!file.is_open()) return "";

		bool foundGroup = false;
		bool foundKey = false;
		
		std::stringstream kstream;
		std::stringstream vstream;

		std::string line;
		while (std::getline(file, line)) {
			if (line[0] == '[') {
				if (foundGroup == true)
					return "";
				if (line.substr(line.begin + 1, line.size - 2) == group)
					foundGroup = true;
			}
			else if (foundGroup == true) {
				char c = 'x';
				short counter = 0;
				while (true) {
					if (counter == size - 2) {
						if (foundKey == true) {
							const std::string value = vstream.str();
							return value;
						}
						else break;
					}
					else {
						c = line[counter];
						if (c == '=') {
							if (kstream.str() == key)
								foundKey = true;
							else break;
						}
						else if (c == ' ') {
							continue;
						}
						else {
							if (foundkey == false)
								kstream << c;
							else
								vstream << c;
						}
						counter++;
					}
				}
			}
			else {
				continue;
			}
		}
	}
};
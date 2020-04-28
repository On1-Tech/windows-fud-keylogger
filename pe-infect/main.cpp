#include "pch.h"
#include "load_pe_mem/loadpe.h"

int main() {
	std::cout << "[+] START" << std::endl;
	const auto raw = loadpe::loadFile("C:\\Users\\Admin\\Desktop\\windows-fud-keylogger-r32.exe");
	loadpe::runPE(raw);
	std::cout << "[-] END" << std::endl;
	std::cin.get();
}
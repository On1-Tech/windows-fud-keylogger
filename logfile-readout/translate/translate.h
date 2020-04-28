#pragma once
#include "pch.h"
#include "keytranslationsets/keyfilters.h"

class translator {
private:
	enum modifier {
		mod_mless, mod_shift, mod_altgr, mod_undefined
	};
	
	std::ifstream binfile;
	std::wofstream txtfile;

	bool writeComposer(const modifier& mod, int keycode);
	uint8_t readNextByte();
	int toKeycode(uint8_t i);
	modifier getMod(uint8_t i);

	template<typename T>
	void write(T w);

public:
	translator(const std::string& binfname, const std::string& txtfname);
	void translate();
};
#include "pch.h"
#include "translate.h"

constexpr uint8_t VK_WINDOWCHANGE = 0x05;

template<typename T>
void translator::write(T w) {
	txtfile << w;
}

bool translator::writeComposer(const modifier& mod, int keycode) {
	if (keycode > 255 || mod == mod_undefined) return false;
	using namespace keysets::german_qwertz;
	std::wstring ws;
	wchar_t wc = '\0';
	
	functional(keycode, ws);
	if (!ws.empty()) {
		write(ws);
		wss << ws;
		return true;
	}
	switch (mod) {
	case mod_mless: simple(keycode, wc); break;
	case mod_shift: shift(keycode, wc); break;
	case mod_altgr: altgr(keycode, wc); break;
	default: break;
	}

	if (wc != '\0') {
		write(wc);
		wss << wc;
		return true;
	}
	
	return false;
}

uint8_t translator::readNextByte() {
	uint8_t i = 0x00;
	binfile.read(reinterpret_cast<char*>(&i), 1);
	return i;
}

int translator::toKeycode(uint8_t i) {
	i &= 0b00111111;
	
	switch (i) {
	case 0x35: return VK_BACK;
	case 0x36: return VK_RETURN;
	case 0x38: return VK_SPACE;
	case 0x39: return VK_MULTIPLY;
	case 0x3A: return VK_ADD;
	case 0x3B: return VK_SEPARATOR;
	case 0x3C: return VK_SUBTRACT;
	case 0x3D: return VK_DECIMAL;
	case 0x3E: return VK_DIVIDE;
	case 0x03: return VK_OEM_1;
	case 0x04: return VK_OEM_2;
	case 0x05: return VK_OEM_3;
	case 0x06: return VK_OEM_4;
	case 0x07: return VK_OEM_5;
	case 0x08: return VK_OEM_6;
	case 0x09: return VK_OEM_7;
	case 0x0A: return VK_OEM_PERIOD;
	case 0x0B: return VK_OEM_MINUS;
	case 0x0C: return VK_OEM_COMMA;
	case 0x0D: return VK_OEM_PLUS;
	case 0x0E: return VK_OEM_102;
	default: break;
	}
	
	if (i > 0x40 - 0x32 && i < 0x5B - 0x32) return i + 0x32;
	if (i > 0x2F - 0x06 && i < 0x3A - 0x06) return i + 0x06;
	if (i > 0x5F - 0x36 && i < 0x6A - 0x36) return i + 0x36;
	
	return 0x00;
}

translator::modifier translator::getMod(uint8_t i) {
	i &= 0b11000000;
	if (i == 0b00000000) return mod_mless;
	if (i == 0b01000000) return mod_shift;
	if (i == 0b10000000) return mod_altgr;
	return mod_undefined;
}

translator::translator(const std::string& binfname, const std::string& txtfname) {
	binfile.open(binfname, std::ios::binary);
	if (!binfile.is_open()) {
		return;
	}
	txtfile.open(txtfname);
	if (!txtfile.is_open()) {
		binfile.close(); return;
	}

	uint8_t b = readNextByte();
	while (b != 0x00) {
		const auto m = getMod(b);
		const auto c = toKeycode(b);
		writeComposer(m, c);
		b = readNextByte();
	}

	binfile.close(); txtfile.close();
	std::wcout << "RES: " << wss.str() << std::endl;
	std::cin.get();
}

#pragma once

class logging {
public:
	virtual bool log(const char c) = 0;
	virtual bool log(const std::string& str) = 0;
	virtual ~logging() = 0; 
};
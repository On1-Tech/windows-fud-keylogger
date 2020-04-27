#pragma once
#include "pch.h"
#include "logFILE/file.h"

//using this function constexpr to replace polymorphism
//resulting in smaller code
//also necessary because pointers are not supported by shellcode

template<typename T>
constexpr auto LOG(T c) { return logFILE::get().log(c); }
#define INIT_LOG logFILE::get().init(FNAME)
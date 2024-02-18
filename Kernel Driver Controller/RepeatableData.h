#pragma once

#include <cstdint>

#include "kernelinterface.hpp"


namespace Data {

	extern KernelInterface *Driver;
	extern ULONG64 client_dll;
	extern ULONG ProcessID;

	extern int screen_width;
	extern int screen_height;

	bool init();

}
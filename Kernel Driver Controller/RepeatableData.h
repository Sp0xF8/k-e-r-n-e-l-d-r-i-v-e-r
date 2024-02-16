#pragma once

#include <cstdint>

#include "kernelinterface.hpp"


namespace Data {

	extern KernelInterface *Driver;
	extern ULONG client_dll;
	extern ULONG ProcessID;

	extern int screen_width;
	extern int screen_height;

	extern uint64_t LocalPlayerPawn;
	extern uint64_t EntityList;


	bool init();

	bool setup();

}
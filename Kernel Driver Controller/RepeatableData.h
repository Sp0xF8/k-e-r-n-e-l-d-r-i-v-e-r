#pragma once

#include <cstdint>

#include "kernelinterface.hpp"


namespace Data {

	KernelInterface *Driver = new KernelInterface("\\\\.\\KernelDriverNOHOOK");
	ULONG client_dll;
	ULONG ProcessID;

	int screen_width;
	int screen_height;

	uint64_t LocalPlayerPawn;
	uint64_t EntityList;


	bool init();

	bool setup();

}
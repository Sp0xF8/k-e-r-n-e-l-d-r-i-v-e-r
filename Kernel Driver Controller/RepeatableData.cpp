

#include "RepeatableData.h"

#include "offsets.h"



namespace Data {

	//KernelInterface* Driver = new KernelInterface("\\\\.\\KernelDriverNOHOOK");
	ULONG client_dll;
	ULONG ProcessID;

	int screen_width;
	int screen_height;

	uint64_t LocalPlayerPawn;
	uint64_t EntityList;
}


bool Data::init() 
{

	/*
	client_dll = Driver->GetClientAddress();
	if (!client_dll) {
		return false;
	}

	ProcessID = Driver->GetProcessID();

	if (!ProcessID) {

		return false;
	}

	*/

	screen_height = GetSystemMetrics(SM_CYSCREEN);
	screen_width = GetSystemMetrics(SM_CXSCREEN);

	return true;
}


bool Data::setup() {

	if(!init()) {
		return false;
	}

	/*
	Data::LocalPlayerPawn = Driver->ReadVirtualMemory<uint64_t>(ProcessID, client_dll + Offsets::Client::dwLocalPlayerPawn, sizeof(uint64_t));

	if (!Data::LocalPlayerPawn) {
		return false;
	}
	

	Data::EntityList = Driver->ReadVirtualMemory<uint64_t>(ProcessID, client_dll + Offsets::Client::dwEntityList, sizeof(uint64_t));

	if (!Data::EntityList) {
		return false;
	}
	*/

	



}



#include "RepeatableData.h"
#include "communication.hpp"
#include "offsets.h"
#include <iostream>



namespace Data {

	KernelInterface* Driver = new KernelInterface("\\\\.\\KernelDriverNOHOOK");
	ULONG64 client_dll;
	ULONG ProcessID;

	int screen_width;
	int screen_height;
}


bool Data::init() 
{
	/*
	client_dll = Driver->GetClientAddress();
	if (client_dll == 0) {
		return false;
	}

	MessageBox(0, "Received Clientaddress", "recieved data!", MB_OK | MB_ICONINFORMATION);

#ifdef _DEBUG
	std::cout << "Client Address: " << std::hex << client_dll << std::endl;
#endif

	ProcessID = Driver->GetProcessID();

	if (ProcessID == 0) {
		return false;
	}

	MessageBox(0, "Received ProcessID", "recieved data!", MB_OK | MB_ICONINFORMATION);

	
	*/

	_KERNEL_INFO_REQUEST Info = Driver->GetInfo();

	client_dll = Info.BaseAddress;
	if (client_dll == 0) {
		return false;
	}

	ProcessID = Info.ProcessID;
	if (ProcessID == 0) {
		return false;
	}

	#ifdef _DEBUG
		std::cout << "Client Address: " << std::hex << client_dll << std::endl;
	#endif
	
	

	screen_height = GetSystemMetrics(SM_CYSCREEN);
	screen_width = GetSystemMetrics(SM_CXSCREEN);

	return true;
}




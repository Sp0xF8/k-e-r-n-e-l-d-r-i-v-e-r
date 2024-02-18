

#include "RepeatableData.h"

#include "offsets.h"



namespace Data {

	KernelInterface* Driver = new KernelInterface("\\\\.\\KernelDriverNOHOOK");
	ULONG client_dll;
	ULONG ProcessID;

	int screen_width;
	int screen_height;
}


bool Data::init() 
{

	
	client_dll = Driver->GetClientAddress();
	if (client_dll == 0) {
		return false;
	}

	MessageBox(0, "Received Clientaddress", "recieved data!", MB_OK | MB_ICONINFORMATION);

	ProcessID = Driver->GetProcessID();

	if (ProcessID == 0) {
		return false;
	}

	MessageBox(0, "Received ProcessID", "recieved data!", MB_OK | MB_ICONINFORMATION);

	

	screen_height = GetSystemMetrics(SM_CYSCREEN);
	screen_width = GetSystemMetrics(SM_CXSCREEN);

	return true;
}




#pragma warning(disable: 4047)

#include "listeners.h"
#include "data.h"
#include "messages.h"


PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo)
{
	UNREFERENCED_PARAMETER(ProcessId);
	UNREFERENCED_PARAMETER(ImageInfo);

	//DebugMessage("Image Loaded:	%ls\n", FullImageName->Buffer);

	//DebugMessage("Image Loaded:	%ls\n", FullImageName->Buffer);
	
	if(wcsstr(FullImageName->Buffer, L"\\Steam\\steamapps\\common\\Counter-Strike Global Offensive\\game\\csgo\\bin\\win64\\client.dll"))
	{
		DebugMessage("CSGO CLIENT.DLL FOUND!\n");
		DebugMessage("DLL Address:	0x%p\n", ImageInfo->ImageBase);
		DebugMessage("Process ID:	%d\n", ProcessId);
		CSClient_DllBase = ImageInfo->ImageBase;
		CSClient_ProcessID = ProcessId;
	}
	

	return STATUS_SUCCESS;
}
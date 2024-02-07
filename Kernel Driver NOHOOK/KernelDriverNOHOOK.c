#pragma warning (disable: 4100)

#include "KernelDriverNOHOOK.h"


NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegPath)
{
	pDriverObject->DriverUnload = UnloadDriver;

	return STATUS_SUCCESS;
}

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject)
{
	
	return STATUS_SUCCESS;
}
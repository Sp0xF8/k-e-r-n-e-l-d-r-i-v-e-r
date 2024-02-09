#pragma warning (disable: 4100 4047 4024)

#include "KernelDriverNOHOOK.h"
#include "messages.h"
#include "listeners.h"
#include "data.h"
#include "communication.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegPath)
{
	UNREFERENCED_PARAMETER(pRegPath);

	pDriverObject->DriverUnload = UnloadDriver;

	DebugMessage("Driver Loaded Successfully!\n");


	PsSetLoadImageNotifyRoutine(ImageLoadCallback);

	RtlInitUnicodeString(&dev, L"\\Device\\KernelDriverNOHOOK");
	RtlInitUnicodeString(&dos, L"\\DosDevices\\KernelDriverNOHOOK");

	IoCreateDevice(pDriverObject, 0, &dev, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &pDeviceObject);
	IoCreateSymbolicLink(&dos, &dev);

	pDriverObject->MajorFunction[IRP_MJ_CREATE]			= CreateCall;
	pDriverObject->MajorFunction[IRP_MJ_CLOSE]			= CloseCall;
	pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = IoControl;

	pDeviceObject->Flags |= DO_DIRECT_IO;
	pDeviceObject->Flags &= ~DO_DEVICE_INITIALIZING;

	return STATUS_SUCCESS;
}

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject)
{
	UNREFERENCED_PARAMETER(pDriverObject);

	PsRemoveLoadImageNotifyRoutine(ImageLoadCallback);
	
	DebugMessage("Driver Unloaded Successfully!\n");

	IoDeleteSymbolicLink(&dos);
	IoDeleteDevice(pDriverObject->DeviceObject);


	return STATUS_SUCCESS;
}
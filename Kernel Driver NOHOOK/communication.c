#include "communication.h"
#include "data.h"
#include "messages.h"

NTSTATUS CreateCall(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);

	DebugMessage("CreateCall\n");

	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;

	IoCompleteRequest(Irp, IO_NO_INCREMENT);

	return STATUS_SUCCESS;
}

NTSTATUS CloseCall(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);

	DebugMessage("CloseCall\n");

	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;

	IoCompleteRequest(Irp, IO_NO_INCREMENT);

	return STATUS_SUCCESS;
}

NTSTATUS IoControl(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);

	NTSTATUS Status = STATUS_UNSUCCESSFUL;
	ULONG BytesIO = 0;

	PIO_STACK_LOCATION Stack = IoGetCurrentIrpStackLocation(Irp);

	ULONG ControlCode = Stack->Parameters.DeviceIoControl.IoControlCode;

	if (ControlCode == IO_GET_CLIENTADDRESS)
	{
		DebugMessage("IO_GET_CLIENTADDRESS\n");

		// Get the address of the client.dll)
		PULONG outputbuffer = (PULONG)Irp->AssociatedIrp.SystemBuffer;

		*outputbuffer = (ULONG)CSClient_DllBase;

		Status = STATUS_SUCCESS;
		BytesIO = sizeof(*outputbuffer);

	}
	else
	{
		BytesIO = 0;
		DebugMessage("Unknown IOCTL\n");
	}

	Irp->IoStatus.Status = Status;
	Irp->IoStatus.Information = BytesIO;

	IoCompleteRequest(Irp, IO_NO_INCREMENT);

	return STATUS_SUCCESS;
}
#pragma warning(disable: 4022)

#include "communication.h"
#include "data.h"
#include "messages.h"
#include "memory.h"

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

	switch (ControlCode) {
		case IO_GET_CLIENTADDRESS:
			DebugMessage("IO_GET_CLIENTADDRESS\n");

			// Get the address of the client.dll)
			PULONG outputbuffer = (PULONG)Irp->AssociatedIrp.SystemBuffer;

			*outputbuffer = (ULONG)CSClient_DllBase;

			Status = STATUS_SUCCESS;
			BytesIO = sizeof(*outputbuffer);

			break;

		case IO_GET_PROCESSID:
			DebugMessage("IO_GET_PROCESSID\n");

			// Get the ProcessId)
			PULONG outputbuffer2 = (PULONG)Irp->AssociatedIrp.SystemBuffer;

			*outputbuffer2 = (ULONG)ProcessID;

			Status = STATUS_SUCCESS;
			BytesIO = sizeof(*outputbuffer2);

			break;

		case IO_READ_REQUEST:
			DebugMessage("IO_READ_REQUEST\n");

			PKERNEL_READ_REQUEST ReadRequest = (PKERNEL_READ_REQUEST)Irp->AssociatedIrp.SystemBuffer;

			PEPROCESS Process;

			if(NT_SUCCESS(PsLookupProcessByProcessId(ReadRequest->ProcessId, &Process))) {
				KernelReadVirtualMemory(Process, ReadRequest->Address, ReadRequest->Buffer, ReadRequest->Size);
				Status = STATUS_SUCCESS;
				BytesIO = sizeof(KERNEL_READ_REQUEST);
			}

			break;

		case IO_WRITE_REQUEST:
			DebugMessage("IO_WRITE_REQUEST\n");

			PKERNEL_WRITE_REQUEST WriteRequest = (PKERNEL_WRITE_REQUEST)Irp->AssociatedIrp.SystemBuffer;

			if(NT_SUCCESS(PsLookupProcessByProcessId(WriteRequest->ProcessId, &Process))) {
				KernelWriteVirtualMemory(Process, WriteRequest->Buffer, WriteRequest->Address, WriteRequest->Size);
				Status = STATUS_SUCCESS;
				BytesIO = sizeof(KERNEL_WRITE_REQUEST);
			}

			break;

		default:
			BytesIO = 0;
			DebugMessage("Unknown IOCTL\n");
			break;
	}

	Irp->IoStatus.Status = Status;
	Irp->IoStatus.Information = BytesIO;

	IoCompleteRequest(Irp, IO_NO_INCREMENT);

	return STATUS_SUCCESS;
}
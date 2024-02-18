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
			PULONG64 outputbuffer = (PULONG64)Irp->AssociatedIrp.SystemBuffer;

			*outputbuffer = (PULONG64)CSClient_DllBase;

			Status = STATUS_SUCCESS;
			BytesIO = sizeof(*outputbuffer);

			break;

		case IO_GET_PROCESSID:
			DebugMessage("IO_GET_PROCESSID\n");

			// Get the ProcessId)
			PULONG outputbuffer2 = (PULONG)Irp->AssociatedIrp.SystemBuffer;

			*outputbuffer2 = (ULONG)CSClient_ProcessID;

			Status = STATUS_SUCCESS;
			BytesIO = sizeof(*outputbuffer2);

			break;

		case IO_READ_REQUEST:
			DebugMessage("IO_READ_REQUEST\n");

			PKERNEL_READ_REQUEST ReadRequest = (PKERNEL_READ_REQUEST)Irp->AssociatedIrp.SystemBuffer;

			DebugMessage("ReadRequest->ProcessId: %d\n", ReadRequest->ProcessId);
			DebugMessage("ReadRequest->Address: 0x%p\n", ReadRequest->Address);
			DebugMessage("ReadRequest->Size: %d\n", ReadRequest->Size);
			if(NT_SUCCESS(KernelReadVirtualMemory(ReadRequest->ProcessId, ReadRequest->Address, ReadRequest->Buffer, ReadRequest->Size))) {
				
				Status = STATUS_SUCCESS;
				BytesIO = sizeof(KERNEL_READ_REQUEST);
			}

			//print data in read request.buffer

			DebugMessage("ReadRequest->Buffer: %lld\n", ReadRequest->Buffer);

			break;

		case IO_WRITE_REQUEST:
			DebugMessage("IO_WRITE_REQUEST\n");

			PKERNEL_WRITE_REQUEST WriteRequest = (PKERNEL_WRITE_REQUEST)Irp->AssociatedIrp.SystemBuffer;

			if(NT_SUCCESS(KernelWriteVirtualMemory(WriteRequest->ProcessId, WriteRequest->Buffer, WriteRequest->Address, WriteRequest->Size))) {
				Status = STATUS_SUCCESS;
				BytesIO = sizeof(KERNEL_WRITE_REQUEST);
			}

			break;

		case IO_REQUEST_INFO:

			DebugMessage("IO_REQUEST_INFO\n");

			PKERNEL_INFO_REQUEST InfoRequest = (PKERNEL_INFO_REQUEST)Irp->AssociatedIrp.SystemBuffer;

			InfoRequest->BaseAddress = (ULONG64)CSClient_DllBase;
			InfoRequest->ProcessID = (ULONG)CSClient_ProcessID;

			Status = STATUS_SUCCESS;
			BytesIO = sizeof(KERNEL_INFO_REQUEST);

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
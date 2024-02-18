
#include "memory.h"




NTSTATUS KernelReadVirtualMemory(ULONG ProcessId, uintptr_t sourceAddress, void* buffer, SIZE_T size) {

    PEPROCESS Process;
    NTSTATUS Status = STATUS_SUCCESS;

    SIZE_T Bytes = 0;

    Status = PsLookupProcessByProcessId((HANDLE)ProcessId, &Process);
    if (!NT_SUCCESS(Status)) {
		return Status;
	}

    Status = MmCopyVirtualMemory(Process, (void*)sourceAddress, PsGetCurrentProcess(), (void*)buffer, size, KernelMode, &Bytes);
    

    return Status;
}

NTSTATUS KernelWriteVirtualMemory(PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size) {
	PSIZE_T Bytes;

    

    return MmCopyVirtualMemory(PsGetCurrentProcess(), SourceAddress, Process, TargetAddress, Size, KernelMode, &Bytes);
}
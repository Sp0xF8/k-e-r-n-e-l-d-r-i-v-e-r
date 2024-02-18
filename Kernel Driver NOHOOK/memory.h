#pragma once
#pragma warning(disable: 4047 4024)


#include "defines.h"


NTSTATUS KernelReadVirtualMemory(ULONG ProcessId, ULONG64 sourceAddress, PVOID buffer, SIZE_T size);

NTSTATUS KernelWriteVirtualMemory(PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size);
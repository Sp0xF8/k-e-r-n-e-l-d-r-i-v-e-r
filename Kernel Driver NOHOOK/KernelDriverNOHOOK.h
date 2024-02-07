#pragma once

#include <ntifs.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegPath);

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject);
#pragma once

#include "communication.hpp"

class KernelInterface
{
public:
	HANDLE hDriver;

	KernelInterface(LPCSTR RegistryPath)
	{
		hDriver = CreateFileA(RegistryPath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
	}

	DWORD GetClientAddress() {
		if(hDriver == INVALID_HANDLE_VALUE)
			return 0;

		ULONGLONG Address;
		DWORD Bytes;

		if(DeviceIoControl(hDriver, IO_GET_CLIENTADDRESS, 0, 0, &Address, sizeof(Address), &Bytes, 0))
			return Address;


		return 0;
	}

	DWORD GetProcessID() {
		if (hDriver == INVALID_HANDLE_VALUE)
			return 0;

		ULONG ProcID;
		DWORD Bytes;

		if (DeviceIoControl(hDriver, IO_GET_PROCESSID, 0, 0, &ProcID, sizeof(ProcID), &Bytes, 0)) {
		
			
			return ProcID;
		}

		return 0;
	}

	_KERNEL_INFO_REQUEST GetInfo() {
		if (hDriver == INVALID_HANDLE_VALUE)
			return _KERNEL_INFO_REQUEST();

		_KERNEL_INFO_REQUEST Info;
		DWORD Bytes;

		if (DeviceIoControl(hDriver, IO_REQUEST_INFO, &Info, sizeof(Info), &Info, sizeof(Info), &Bytes, 0))
			return Info;

		return _KERNEL_INFO_REQUEST();
	}

	template <typename type>
	type ReadVirtualMemory(ULONG ProcessId, ULONG64 ReadAddress, SIZE_T Size)
	{
		type buffer = type();


		if(hDriver == INVALID_HANDLE_VALUE)
			return buffer;

		KERNEL_READ_REQUEST ReadRequest;

		ReadRequest.ProcessId = ProcessId;
		ReadRequest.Address = ReadAddress;
		ReadRequest.Buffer = &buffer;
		ReadRequest.Size = Size;

		if(DeviceIoControl(hDriver, IO_READ_REQUEST, &ReadRequest, sizeof(ReadRequest), &ReadRequest, sizeof(ReadRequest), 0, 0))
			return buffer;

		return buffer;
	}


	template <typename type>
	bool WriteVirtualMemory(ULONG ProcessId, ULONG WriteAddress, type Buffer, SIZE_T Size)
	{

		if(hDriver == INVALID_HANDLE_VALUE)
			return false;

		DWORD Bytes;


		KERNEL_WRITE_REQUEST WriteRequest;

		WriteRequest.ProcessId = ProcessId;
		WriteRequest.Address = WriteAddress;
		WriteRequest.Buffer = &Buffer;
		WriteRequest.Size = Size;

		if(DeviceIoControl(hDriver, IO_WRITE_REQUEST, &WriteRequest, sizeof(WriteRequest), 0, 0, &Bytes, 0))
			return true;

		return false;
	}

};

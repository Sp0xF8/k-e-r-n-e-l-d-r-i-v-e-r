// Kernel Driver Controller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "kernelinterface.hpp"

int main()
{
    KernelInterface Driver = KernelInterface("\\\\.\\KernelDriverNOHOOK");

    ULONG Address = Driver.GetClientAddress();

    std::cout << "Client.dll Base Address: " << Address << std::endl;

    std::cin.get();

    return 0;

}


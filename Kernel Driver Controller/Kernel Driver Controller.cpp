// Kernel Driver Controller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "framework.h"
#include <Windows.h>

int main()
{

	if (!Framework::init()) { Framework::shutdown(); }

    std::cout << "Cheat Loaded! - Press END Key to Exit!" << std::endl;

	while (true)
		{
			if (!Framework::run()) { Framework::shutdown(); }

			if (GetAsyncKeyState(VK_END) & 1)
			{
				Framework::shutdown();
				break;
			}
		}

    return 0;

}


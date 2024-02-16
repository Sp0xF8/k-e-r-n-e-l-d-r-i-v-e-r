// Kernel Driver Controller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning(disable : 28251)



#include "framework.h"
#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	if (!Framework::init()) { Framework::shutdown(); }

    //std::cout << "Cheat Loaded! - Press END Key to Exit!" << std::endl;
	
	while (true)
		{

			MSG msg = { 0 };
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_QUIT)
				{

					
					break;
				}
			}
			else
			{
				if (!Framework::run()) { Framework::shutdown(); }

				if (GetAsyncKeyState(VK_END) & 1)
				{
					Framework::shutdown();
					break;
				}
			}
		}
	
	


    return 0;

}


#pragma once

#include <d3d11.h>


namespace Visualiser {

	//window variables
	extern HWND hWnd; //window handle
	extern HINSTANCE hInstance; //application instance
	extern int nCmdShow; //show window command

	//directx 11 variables
	extern IDXGISwapChain* pSwapChain;
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pDeviceContext;
	extern ID3D11RenderTargetView* pRenderTarget;

	int Init();

	void Run();

	bool CALLBACK CreateDX11Window();
	void DestroyDX11Window();

	bool CreateRenderTarget();

	bool BeingScene();
	bool EndScene();


	bool CreateDeviceD3D(HWND hWnd);
	void DestroyDeviceD3D();



}

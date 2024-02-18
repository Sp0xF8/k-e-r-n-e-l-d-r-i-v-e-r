#pragma once


#include <Windows.h>
#include <thread>

#include <dwmapi.h>
#include <d3d11.h>
#include <windowsx.h>
#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx11.h"
#include "Imgui/imgui_impl_win32.h"



namespace Visualiser
{

	extern int			pCmdShow;

	extern HINSTANCE	hInstance;
	extern HWND			hwnd;

	extern ID3D11Device*				g_pd3dDevice;
	extern ID3D11DeviceContext*			g_pd3dDeviceContext;
	extern IDXGISwapChain*				g_pSwapChain;
	extern ID3D11RenderTargetView*		g_mainRenderTargetView;


	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


	bool Init();

	bool CreatepWindow();
	bool DestroypWindow();

	bool CreateDeviceD3D();
	bool CleanupDeviceD3D();
	bool CreateRenderTarget();
	bool CleanupRenderTarget();


	bool SetupImgui();
	void CleanupImgui();

	void RenderFrame();


	void Shutdown();
}


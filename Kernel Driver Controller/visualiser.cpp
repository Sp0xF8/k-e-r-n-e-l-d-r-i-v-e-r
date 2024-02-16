#include "visualiser.h"

#include "RepeatableData.h"


//creating a window and setting up the directx 11 device, ready to render directx objects

namespace Visualiser {

	//window variables
	HWND hWnd; //window handle
	HINSTANCE hInstance; //application instance
	int nCmdShow = 1; //show window command

	//directx 11 variables
	IDXGISwapChain* pSwapChain = NULL;
	ID3D11Device* pDevice = NULL;
	ID3D11DeviceContext* pDeviceContext = NULL;
	ID3D11RenderTargetView* pRenderTarget = NULL;


	
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	return DefWindowProc(hWnd, message, wParam, lParam);
}

bool CALLBACK Visualiser::CreateDX11Window() {

	//create the window
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "WindowsClass", NULL};

	wc.hInstance = hInstance;
	

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "CreateDX11Window::Error registering class", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	hWnd = CreateWindowEx(0, "WindowsClass", "DirectX11", WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, 100, 100, 800, 600, NULL, NULL, wc.hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, "CreateDX11Window::Error creating window", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	//SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 50, LWA_COLORKEY | LWA_ALPHA);

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	return true;
}


bool Visualiser::CreateDeviceD3D(HWND hwnd) {

	//create the swap chain
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 99;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hwnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	UINT createDeviceFlags = 0;

	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[1] = { D3D_FEATURE_LEVEL_11_0 };

	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 1, D3D11_SDK_VERSION, &sd, &pSwapChain, &pDevice, &featureLevel, &pDeviceContext) != S_OK) {
		MessageBox(NULL, "CreateDeviceD3D::Error creating device and swap chain", "Error", MB_OK | MB_ICONERROR);
		return false;
	}



	return true;
}


void Visualiser::DestroyDeviceD3D() {

	if (pDeviceContext) pDeviceContext->ClearState();
	if (pSwapChain) pSwapChain->Release();
	if (pDeviceContext) pDeviceContext->Release();
	if (pDevice) pDevice->Release();
}



void Visualiser::DestroyDX11Window() {

	DestroyDeviceD3D();
	DestroyWindow(hWnd);
	UnregisterClass("WindowsClass", NULL);
}


bool Visualiser::CreateRenderTarget() {

	//create the render target
	ID3D11Texture2D* pBackBuffer;
	if (pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer) != S_OK) {
		MessageBox(NULL, "CreateRenderTarget::Error getting buffer", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	if (pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRenderTarget) != S_OK) {
		MessageBox(NULL, "CreateRenderTarget::Error creating render target view", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	pBackBuffer->Release();
	return true;
}



bool Visualiser::BeingScene() {

	//set background color
	float transparent[4] = { 0.25f, 0.5f, 1.0f, 1.0f };

	//clear the render target
	pDeviceContext->ClearRenderTargetView(pRenderTarget, transparent);



	//begin the scene
	return true;
}

bool Visualiser::EndScene() {


	pSwapChain->Present(1, 0);

	//end the scene
	return true;
}


int Visualiser::Init() {

	CreateDX11Window();

	CreateDeviceD3D(hWnd);


	return 0;
}

void Visualiser::Run() {

	// Run the game loop

	BeingScene();

	EndScene();
}	


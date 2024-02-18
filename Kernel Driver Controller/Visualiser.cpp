#include "Visualiser.h"

#include "RepeatableData.h"


#include "visuals.h"



namespace Visualiser {

	int pCmdShow = 0;

	HINSTANCE	hInstance	= NULL;
	HWND		hWnd		= NULL;

	ID3D11Device*				g_pd3dDevice			= NULL;
	ID3D11DeviceContext*		g_pd3dDeviceContext		= NULL;
	IDXGISwapChain*				g_pSwapChain			= NULL;
	ID3D11RenderTargetView*		g_mainRenderTargetView	= NULL;
}




extern IMGUI_IMPL_API LRESULT  ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK Visualiser::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
	{
		return true;
	}

	switch (msg)
	{
	case WM_NCHITTEST:
	{
		const LONG border_width = GetSystemMetrics(SM_CXSIZEFRAME);
		const LONG titlebar_height = GetSystemMetrics(SM_CYCAPTION);

		POINT cursor = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
		RECT window;
		GetWindowRect(hWnd, &window);

		if (cursor.y >= window.top && cursor.y < window.top + titlebar_height)
		{
			return HTCAPTION;
		}
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


bool Visualiser::CreatepWindow()
{
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = "Visualiser";

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(
		WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
		"Visualiser",
		"Visualiser",
		WS_POPUP,
		0,
		0,
		Data::screen_width,
		Data::screen_height,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBoxA(0, "Visualiser::CreatepWindow : Failed to create window", "Error", MB_OK);
		return false;
	}

	SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), BYTE(255), LWA_ALPHA);

	RECT client_rect{};
	GetClientRect(hWnd, &client_rect);

	RECT window_rect{};
	GetWindowRect(hWnd, &window_rect);

	POINT diff{};

	ClientToScreen(hWnd, &diff);

	const MARGINS margins{
		window_rect.left + (diff.x - window_rect.left),
		window_rect.top + (diff.y - window_rect.top),
		client_rect.right,
		client_rect.bottom
	};

	DwmExtendFrameIntoClientArea(hWnd, &margins);

	
	return true;
}

bool Visualiser::DestroypWindow()
{
	if (hWnd)
	{
		DestroyWindow(hWnd);
		UnregisterClass("Visualiser", hInstance);
		return true;
	}
	return true;
}

bool Visualiser::CreateDeviceD3D()
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 99;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	constexpr D3D_FEATURE_LEVEL feature_levels[2]{ 
		D3D_FEATURE_LEVEL_11_0, 
		D3D_FEATURE_LEVEL_10_0 
	};

	if (D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		0,
		feature_levels,
		2,
		D3D11_SDK_VERSION,
		&sd,
		&g_pSwapChain,
		&g_pd3dDevice,
		NULL,
		&g_pd3dDeviceContext) != S_OK)
	{
		MessageBoxA(0, "Visualiser::CreateDeviceD3D : Failed to create device and swap chain", "Error", MB_OK);
		return false;
	}
}

bool Visualiser::CleanupDeviceD3D()
{
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
	CleanupRenderTarget();
	return true;
}

bool Visualiser::CreateRenderTarget()
{
	
	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));

	if (pBackBuffer) {
		g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
		pBackBuffer->Release();
	}
	else {
		MessageBoxA(0, "Visualiser::CreateRenderTarget : Failed to create render target", "Error", MB_OK);
		return false;
	}


	ShowWindow(hWnd, pCmdShow);
	UpdateWindow(hWnd);


	return true;
}

bool Visualiser::CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
	return true;
}


bool Visualiser::SetupImgui()
{
	ImGui::CreateContext();

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

	return true;
}

void Visualiser::CleanupImgui()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void Visualiser::RenderFrame()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	//ImGui::ShowDemoWindow();

	Visuals::ESP();
	

	ImGui::Render();
	
	float clear_color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	
	g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);

	g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color);

	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	g_pSwapChain->Present(0, 0);
}






bool Visualiser::Init()
{

	if (!CreatepWindow()) {
		MessageBoxA(0, "Visualiser::Init : Failed to create window", "Error", MB_OK);
		return false;
	}

	if (!CreateDeviceD3D()) {
		MessageBoxA(0, "Visualiser::Init : Failed to create device and swap chain", "Error", MB_OK);
		return false;
	}

	if (!CreateRenderTarget()) {
		MessageBoxA(0, "Visualiser::Init : Failed to create render target", "Error", MB_OK);
		return false;
	}

	if (!SetupImgui()) {
		MessageBoxA(0, "Visualiser::Init : Failed to setup imgui", "Error", MB_OK);
		return false;
	}

	return true;
}

void Visualiser::Shutdown()
{
	CleanupImgui();
	CleanupDeviceD3D();
	DestroypWindow();
}



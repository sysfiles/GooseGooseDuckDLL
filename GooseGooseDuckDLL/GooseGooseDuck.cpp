#include <windows.h>
#include <d3d11.h>

#include "GooseGooseDuck.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"

#include "imgui/imgui_internal.h"

PVOID BaseModule = NULL;
PVOID GameAssembly = NULL;

typedef HRESULT(STDMETHODCALLTYPE* PRESENT_T)(IDXGISwapChain*, UINT, UINT);

PRESENT_T Present = NULL;
UCHAR PresentHookCode[5];
UCHAR PresentOriginCode[5];

BOOL PresentInit = FALSE;

ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* pRTView;

HRESULT STDMETHODCALLTYPE PresentHookFunc(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

VOID GooseGooseDuckMain()
{
	BaseModule = GetModuleHandle(NULL);

	while (!GameAssembly)
	{
		GameAssembly = GetModuleHandle(L"GameAssembly.dll");
		Sleep(1000);
	}

	WNDCLASSEX wc{ 0 };
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = DefWindowProc;
	wc.lpszClassName = L"Goose Goose Duck";

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"DX初始化失败 Step: 1", L"错误", MB_ICONWARNING);
		ExitProcess(0);
	}

	HWND hWnd = CreateWindow(wc.lpszClassName, L"", WS_DISABLED, 0, 0, 0, 0, NULL, NULL, NULL, NULL);

	DXGI_SWAP_CHAIN_DESC swapChainDesc{ 0 };
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Windowed = TRUE;

	D3D_FEATURE_LEVEL featureLevel;

	IDXGISwapChain* pDummySwapChain = NULL;
	ID3D11Device* pDummyDevice = NULL;

	HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, NULL, 0, D3D11_SDK_VERSION, &swapChainDesc, &pDummySwapChain, &pDummyDevice, &featureLevel, NULL);
	if (FAILED(hr))
	{
		DestroyWindow(swapChainDesc.OutputWindow);
		UnregisterClass(wc.lpszClassName, (HINSTANCE)BaseModule);

		MessageBox(NULL, L"DX初始化失败 Step: 2", L"错误", MB_ICONWARNING);
		ExitProcess(0);
	}

	Present = (PRESENT_T)(*(VOID***)pDummySwapChain)[8];

	PCHAR ReJmpAddr = NULL;

	ULONG_PTR TryAllocAddr = (ULONG_PTR)Present % 0x1000 > 0 ? (ULONG_PTR)Present + (0x1000 - (ULONG_PTR)Present % 0x1000) : (ULONG_PTR)Present;
	for (SIZE_T i = 0; i < 0x80000; i++)
	{
		ReJmpAddr = (PCHAR)VirtualAlloc((PVOID)(TryAllocAddr + i * 0x1000), 4096, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (ReJmpAddr)
		{
			break;
		}
	}

	if (!ReJmpAddr)
	{
		MessageBox(NULL, L"DX初始化失败 Step: 3", L"错误", MB_ICONWARNING);
		ExitProcess(0);
	}

	UCHAR ReJmpCode[14] = { 0xff, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	*((PVOID*)&ReJmpCode[6]) = (PVOID)PresentHookFunc;
	memcpy(ReJmpAddr, &ReJmpCode, 14);

	DWORD OldProtect;
	if (VirtualProtect((PVOID)Present, 5, PAGE_EXECUTE_READWRITE, &OldProtect))
	{
		PresentHookCode[0] = 0xE9;
		*((PDWORD)&PresentHookCode[1]) = (DWORD)(ReJmpAddr - (PCHAR)Present - 5);

		memcpy(&PresentOriginCode, (PVOID)Present, 5);
		memcpy((PVOID)Present, &PresentHookCode, 5);
	}
	else
	{
		MessageBox(NULL, L"DX初始化失败 Step: 4", L"错误", MB_ICONWARNING);
		ExitProcess(0);
	}
	
	pDummySwapChain->Release();
	pDummyDevice->Release();

	DestroyWindow(swapChainDesc.OutputWindow);
	UnregisterClass(wc.lpszClassName, (HINSTANCE)BaseModule);
}

HRESULT STDMETHODCALLTYPE PresentHookFunc(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!PresentInit)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRTView);
			pBackBuffer->Release();

			ImGui::CreateContext();
			ImGui_ImplDX11_Init(pDevice, pContext);
			ImGui_ImplWin32_Init(FindWindow(0, L"Goose Goose Duck"));
			ImGuiIO& io = ImGui::GetIO(); (void)io;

			ImVector<ImWchar> ranges;
			ImFontGlyphRangesBuilder builder;

			builder.AddRanges(io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
			builder.AddRanges(io.Fonts->GetGlyphRangesChineseFull());
			builder.AddRanges(io.Fonts->GetGlyphRangesCyrillic());
			builder.AddRanges(io.Fonts->GetGlyphRangesJapanese());
			builder.AddRanges(io.Fonts->GetGlyphRangesKorean());
			builder.AddRanges(io.Fonts->GetGlyphRangesThai());
			builder.AddRanges(io.Fonts->GetGlyphRangesVietnamese());
			builder.BuildRanges(&ranges);

			io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyhbd.ttc", 16.0f, NULL, ranges.Data);
			io.Fonts->Build();

			ImGui::StyleColorsDark();

			PresentInit = TRUE;
		}
	}

	if (PresentInit)
	{
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		
		ImGui::NewFrame();

		ImGui::Begin(u8"玩家信息");
		ImGui::SetWindowPos(ImVec2(20, 400), ImGuiCond_Always);
		ImGui::SetWindowSize(ImVec2(350, 400), ImGuiCond_Always);
		ImGui::Text(u8"[序号] 名字 | 身份 | 状态");
		ImGui::Text(u8"[1] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[2] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[3] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[4] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[5] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[6] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[7] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[8] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[9] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[10] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[11] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[12] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[13] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[14] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[15] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::Text(u8"[16] %s | %s | %s", u8"null", u8"null", u8"null");
		ImGui::End();

		ImGui::Render();

		pContext->OMSetRenderTargets(1, &pRTView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	memcpy((PVOID)Present, &PresentOriginCode, 5);
	HRESULT Result = Present(pSwapChain, SyncInterval, Flags);
	memcpy((PVOID)Present, &PresentHookCode, 5);
	return Result;
}

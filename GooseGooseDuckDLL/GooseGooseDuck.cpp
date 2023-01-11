#include <windows.h>
#include <d3d11.h>

#include "GooseGooseDuck.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"

#include "GameData.h"

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
	GameData::BaseModule = GetModuleHandle(NULL);

	while (!GameData::UnityPlayer)
	{
		GameData::UnityPlayer = GetModuleHandle(L"UnityPlayer.dll");
		Sleep(1000);
	}

	while (!GameData::GameAssembly)
	{
		GameData::GameAssembly = GetModuleHandle(L"GameAssembly.dll");
		Sleep(1000);
	}

	GameData::UnityPlayer = GameData::UnityPlayer;


	Sleep(5000);

	IDXGISwapChain* GameSwapChain = (IDXGISwapChain*)((PENCLAVE_ROUTINE)((ULONG_PTR)GameData::UnityPlayer + Offset::UnityPlayer::GetSwapChain))(0);

	Present = (PRESENT_T)(*(VOID***)GameSwapChain)[8];

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

			io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyhbd.ttc", 20.0f, NULL, ranges.Data);
			io.Fonts->Build();

			ImGui::StyleColorsDark();

			PresentInit = TRUE;
		}
	}

	if (PresentInit)
	{
		GameData::UpdateGameData();

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		
		ImGui::NewFrame();

		WCHAR StrBuffer[256] = { 0 };
		CHAR U8Buffer[256] = { 0 };

		if (MenuData::Menu.PlayerInfo)
		{
			ImGui::GetForegroundDrawList()->AddText(ImVec2(20, 400), IM_COL32_WHITE, u8"玩家信息");
			ImGui::GetForegroundDrawList()->AddText(ImVec2(20, 420), IM_COL32_WHITE, u8"[序号] 名字 | 身份 | 状态");

			for (SIZE_T PlayerInfoIndex = 0; PlayerInfoIndex < 16; PlayerInfoIndex++)
			{
				if (!GameData::OtherPlayer[PlayerInfoIndex].IsRoleSet)
				{
					continue;
				}

				wsprintf(StrBuffer, L"[%d] %s | %s | %s", PlayerInfoIndex, GameData::OtherPlayer[PlayerInfoIndex].Name, GameData::OtherPlayer[PlayerInfoIndex].Role, L"null");
				WideCharToMultiByte(CP_UTF8, NULL, StrBuffer, -1, U8Buffer, sizeof(U8Buffer), NULL, NULL);
				ImGui::GetForegroundDrawList()->AddText(ImVec2(20, (float)(440 + PlayerInfoIndex * 20)), IM_COL32_WHITE, U8Buffer);
			}
		}

		ImGui::Render();

		pContext->OMSetRenderTargets(1, &pRTView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	memcpy((PVOID)Present, &PresentOriginCode, 5);
	HRESULT Result = Present(pSwapChain, SyncInterval, Flags);
	memcpy((PVOID)Present, &PresentHookCode, 5);
	return Result;
}

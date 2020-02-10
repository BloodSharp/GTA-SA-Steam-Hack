#include "CH4.h"

HWND hWnd = 0;
WNDPROC hGameWndProc;
bool bInitializeHack = false;

//Soporte de Directx 9
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;
D3DPRESENT_PARAMETERS g_d3dpp;
LPDIRECT3D9 pD3D;

LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

HRESULT(WINAPI* pOrig_EndScene)(IDirect3DDevice9*) = 0;
HRESULT(WINAPI* pOrig_Reset)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*) = 0;

/*
LRESULT CALLBACK HOOK_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (bInitializeHack)
    {
        if (uMsg == WM_KEYDOWN && wParam == VK_INSERT)
        {
            CH4::Interface::Enable = !CH4::Interface::Enable;
        }
        if (CH4::Interface::Enable)
            if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
            {
                return FALSE;
            }
    }
    return CallWindowProc(hGameWndProc, hWnd, uMsg, wParam, lParam);
}
*/
LRESULT(CALLBACK* pOrig_WndProc)(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

LRESULT CALLBACK HOOK_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (bInitializeHack)
    {
        if (uMsg == WM_KEYDOWN && wParam == VK_INSERT)
            CH4::Interface::Enable = !CH4::Interface::Enable;
        if (CH4::Interface::Enable)
            if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
                return FALSE;
    }
    return pOrig_WndProc(hwnd, uMsg, wParam, lParam);
}

HRESULT WINAPI HOOK_Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pD3DParams)
{
    if (bInitializeHack)
        ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT retValue = pOrig_Reset(pDevice, pD3DParams);
    if (bInitializeHack)
        ImGui_ImplDX9_CreateDeviceObjects();
    return retValue;
}

SHORT(WINAPI* pOrig_GetAsyncKeyState)(int vKey) = 0;

SHORT WINAPI HOOK_GetAsyncKeyState(int vKey)
{
    if (CH4::Interface::Enable)
        return 0;
    return pOrig_GetAsyncKeyState(vKey);
}

HRESULT WINAPI HOOK_EndScene(IDirect3DDevice9* pDevice)
{
    if (!bInitializeHack)
    {
        D3DDEVICE_CREATION_PARAMETERS d3d_dcp;
        pDevice->GetCreationParameters(&d3d_dcp);
        hWnd = d3d_dcp.hFocusWindow;
        ImGui::CreateContext();
        //hGameWndProc = (WNDPROC)SetWindowLong(d3d_dcp.hFocusWindow, GWL_WNDPROC, (LONG)HOOK_WndProc);
        pOrig_WndProc = (decltype(pOrig_WndProc))CH4::Utils::DetourFunction((PBYTE)((DWORD)GetModuleHandle(NULL) + 0x0037C230), (PBYTE)HOOK_WndProc);
        ImGui_ImplWin32_Init(d3d_dcp.hFocusWindow);
        ImGui_ImplDX9_Init(pDevice);
        CH4::Interface::Render::Initialize();
        bInitializeHack = true;
    }
    
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGui::GetIO().DeltaTime = 0;

    CH4::Interface::Render::Background();
    CH4::Interface::Render::Interface();

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

    return pOrig_EndScene(pDevice);
}

BOOL(WINAPI* pOrig_SetCursorPos)(int X, int Y) = 0;

BOOL WINAPI HOOK_SetCursorPos(int X, int Y)
{
    if (CH4::Interface::Enable)
        return FALSE;
    return pOrig_SetCursorPos(X, Y);
}

BOOL(WINAPI* pOrig_GetCursorPos)(LPPOINT lpPoint) = 0;

BOOL WINAPI HOOK_GetCursorPos(LPPOINT lpPoint)
{
    if (CH4::Interface::Enable)
        return FALSE;
    return pOrig_GetCursorPos(lpPoint);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if(ul_reason_for_call==DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        /*
        [5148] d3d9.dll = 0x6eed0000
        [5148] EndScene 0x6ef346a0 / 0x646a0
        [5148] Reset 0x6efb67c0 / 0xe67c0
        */
        DWORD dwD3D9 = (DWORD)LoadLibrary("d3d9.dll");
        HMODULE hUser32 = LoadLibrary("User32.dll");
        if (dwD3D9 && hUser32)
        {
            pOrig_EndScene = (decltype(pOrig_EndScene))CH4::Utils::DetourFunction(PBYTE(dwD3D9 + 0x646a0), (PBYTE)HOOK_EndScene);
            //pOrig_Reset = (decltype(pOrig_Reset))CH4::Utils::DetourFunction(PBYTE(dwD3D9 + 0xe67c0), (PBYTE)HOOK_Reset);
            pOrig_SetCursorPos = (decltype(pOrig_SetCursorPos))CH4::Utils::DetourFunction(PBYTE(GetProcAddress(hUser32, "SetCursorPos")), (PBYTE)HOOK_SetCursorPos);
            pOrig_GetCursorPos = (decltype(pOrig_GetCursorPos))CH4::Utils::DetourFunction(PBYTE(GetProcAddress(hUser32, "GetCursorPos")), (PBYTE)HOOK_GetCursorPos);
            pOrig_GetAsyncKeyState = (decltype(pOrig_GetAsyncKeyState))CH4::Utils::DetourFunction((PBYTE)(GetProcAddress(hUser32, "GetAsyncKeyState")), (PBYTE)HOOK_GetAsyncKeyState);
        }
    }
    return TRUE;
}
// dllmain.cpp : Define el punto de entrada de la aplicación DLL.
#include <Windows.h>
#include <d3d9.h>
#include "ch4_lib_utils.h"

IDirect3D9* (WINAPI* pOrig_Direct3DCreate9)(UINT SDKVersion) = 0;
HRESULT(WINAPI* pOrig_CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags,
    D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface) = 0;

PVOID GetInterfaceMethod(PVOID intf, DWORD methodIndex)
{
    return (PVOID)(*(DWORD*)intf + methodIndex * 4);
}

HRESULT WINAPI HOOK_CreateDevice(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags,
    D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    pPresentationParameters->Windowed = TRUE;
    return pOrig_CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
}

IDirect3D9* WINAPI HOOK_Direct3DCreate9(UINT SDKVersion)
{
    IDirect3D9* pD3D = pOrig_Direct3DCreate9(SDKVersion);
    pOrig_CreateDevice = (decltype(pOrig_CreateDevice))CH4::Utils::DetourFunction((PBYTE)GetInterfaceMethod(pD3D, 16), (PBYTE)HOOK_CreateDevice);
    return pD3D;
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD ul_reason_for_call,LPVOID lpReserved)
{
    if(ul_reason_for_call==DLL_PROCESS_ATTACH)
    {
        pOrig_Direct3DCreate9 = (decltype(pOrig_Direct3DCreate9))CH4::Utils::DetourFunction((PBYTE)GetProcAddress(LoadLibrary("d3d9.dll"), "Direct3DCreate9"), (PBYTE)HOOK_Direct3DCreate9);
    }
    return TRUE;
}


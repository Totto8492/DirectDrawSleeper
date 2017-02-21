#include <windows.h>
#include <ddraw.h>
#include "mhook-lib/mhook.h"

struct HookDirectDrawSurface : IDirectDrawSurface
{
    IDirectDrawSurface *p = nullptr;
    WINAPI HRESULT QueryInterface(REFIID riid, void** ppvObject) { return p->QueryInterface(riid, ppvObject); }
    WINAPI ULONG AddRef() { return p->AddRef(); }
    WINAPI ULONG Release() { ULONG ret = p->Release(); if (!ret) { delete this; } return ret; }
    WINAPI HRESULT AddAttachedSurface(LPDIRECTDRAWSURFACE lpDDSAttachedSurface) { return p->AddAttachedSurface(lpDDSAttachedSurface); }
    WINAPI HRESULT AddOverlayDirtyRect(LPRECT lpRect) { return p->AddOverlayDirtyRect(lpRect); }
    WINAPI HRESULT Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
    {
        timeBeginPeriod(1);
        Sleep(20);
        return p->Blt(lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx);
    }
    WINAPI HRESULT BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags) { return p->BltBatch(lpDDBltBatch, dwCount, dwFlags); }
    WINAPI HRESULT BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans) { return p->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans); }
    WINAPI HRESULT DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSAttachedSurface) { return p->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface); }
    WINAPI HRESULT EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) { return p->EnumAttachedSurfaces(lpContext, lpEnumSurfacesCallback); }
    WINAPI HRESULT EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback) { return p->EnumOverlayZOrders(dwFlags, lpContext, lpfnCallback); }
    WINAPI HRESULT Flip(LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride, DWORD dwFlags) { return p->Flip(lpDDSurfaceTargetOverride, dwFlags); }
    WINAPI HRESULT GetAttachedSurface(LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE *lplpDDAttachedSurface) { return p->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface); }
    WINAPI HRESULT GetBltStatus(DWORD dwFlags) { return p->GetBltStatus(dwFlags); }
    WINAPI HRESULT GetCaps(LPDDSCAPS lpDDSCaps) { return p->GetCaps(lpDDSCaps); }
    WINAPI HRESULT GetClipper(LPDIRECTDRAWCLIPPER *lplpDDClipper) { return p->GetClipper(lplpDDClipper); }
    WINAPI HRESULT GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey) { return p->GetColorKey(dwFlags, lpDDColorKey); }
    WINAPI HRESULT GetDC(HDC *lphDC) { return p->GetDC(lphDC); }
    WINAPI HRESULT GetFlipStatus(DWORD dwFlags) { return p->GetFlipStatus(dwFlags); }
    WINAPI HRESULT GetOverlayPosition(LPLONG lplX, LPLONG lplY) { return p->GetOverlayPosition(lplX, lplY); }
    WINAPI HRESULT GetPalette(LPDIRECTDRAWPALETTE *lplpDDPalette) { return p->GetPalette(lplpDDPalette); }
    WINAPI HRESULT GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat) { return p->GetPixelFormat(lpDDPixelFormat); }
    WINAPI HRESULT GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc) { return p->GetSurfaceDesc(lpDDSurfaceDesc); }
    WINAPI HRESULT Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc) { return p->Initialize(lpDD, lpDDSurfaceDesc); }
    WINAPI HRESULT IsLost() { return p->IsLost(); }
    WINAPI HRESULT Lock(LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent) { return p->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent); }
    WINAPI HRESULT ReleaseDC(HDC hDC) { return p->ReleaseDC(hDC); }
    WINAPI HRESULT Restore() { return p->Restore(); }
    WINAPI HRESULT SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper) { return p->SetClipper(lpDDClipper); }
    WINAPI HRESULT SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey) { return p->SetColorKey(dwFlags, lpDDColorKey); }
    WINAPI HRESULT SetOverlayPosition(LONG lX, LONG lY) { return p->SetOverlayPosition(lX, lY); }
    WINAPI HRESULT SetPalette(LPDIRECTDRAWPALETTE lpDDPalette) { return p->SetPalette(lpDDPalette); }
    WINAPI HRESULT Unlock(LPVOID lpSurfaceData) { return p->Unlock(lpSurfaceData); }
    WINAPI HRESULT UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx) { return p->UpdateOverlay(lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx); }
    WINAPI HRESULT UpdateOverlayDisplay(DWORD dwFlags) { return p->UpdateOverlayDisplay(dwFlags); }
    WINAPI HRESULT UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSReference) { return p->UpdateOverlayZOrder(dwFlags, lpDDSReference); }
};

struct HookDirectDraw : IDirectDraw
{
    IDirectDraw *p = nullptr;
    WINAPI HRESULT QueryInterface(REFIID riid, void** ppvObject) { return p->QueryInterface(riid, ppvObject); }
    WINAPI ULONG AddRef() { return p->AddRef(); }
    WINAPI ULONG Release() { ULONG ret = p->Release(); if (!ret) { delete this; } return ret; }
    WINAPI HRESULT Compact() { return p->Compact(); }
    WINAPI HRESULT CreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER *lplpDDClipper, IUnknown *pUnkOuter) { return p->CreateClipper(dwFlags, lplpDDClipper, pUnkOuter); }
    WINAPI HRESULT CreatePalette(DWORD dwFlags, LPPALETTEENTRY lpColorTable, LPDIRECTDRAWPALETTE *lplpDDPalette, IUnknown *pUnkOuter) { return p->CreatePalette(dwFlags, lpColorTable, lplpDDPalette, pUnkOuter); }
    WINAPI HRESULT CreateSurface(LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE *lplpDDSurface, IUnknown *pUnkOuter)
    {
        auto ret = p->CreateSurface(lpDDSurfaceDesc, lplpDDSurface, pUnkOuter);
        if (FAILED(ret) || !(lpDDSurfaceDesc->ddsCaps.dwCaps & DDSCAPS_PRIMARYSURFACE))
        {
            return ret;
        }

        auto obj = new HookDirectDrawSurface();
        obj->p = *lplpDDSurface;
        *lplpDDSurface = obj;
        return ret;
    }
    WINAPI HRESULT DuplicateSurface(LPDIRECTDRAWSURFACE lpDDSurface, LPDIRECTDRAWSURFACE *lplpDupDDSurface) { return p->DuplicateSurface(lpDDSurface, lplpDupDDSurface); }
    WINAPI HRESULT EnumDisplayModes(DWORD dwFlags, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK lpEnumModesCallback) { return p->EnumDisplayModes(dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback); }
    WINAPI HRESULT EnumSurfaces(DWORD dwFlags, LPDDSURFACEDESC lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) { return p->EnumSurfaces(dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback); }
    WINAPI HRESULT FlipToGDISurface() { return p->FlipToGDISurface(); }
    WINAPI HRESULT GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps) { return p->GetCaps(lpDDDriverCaps, lpDDHELCaps); }
    WINAPI HRESULT GetDisplayMode(LPDDSURFACEDESC lpDDSurfaceDesc) { return p->GetDisplayMode(lpDDSurfaceDesc); }
    WINAPI HRESULT GetFourCCCodes(LPDWORD lpNumCodes, LPDWORD lpCodes) { return p->GetFourCCCodes(lpNumCodes, lpCodes); }
    WINAPI HRESULT GetGDISurface(LPDIRECTDRAWSURFACE *lplpGDIDDSurface) { return p->GetGDISurface(lplpGDIDDSurface); }
    WINAPI HRESULT GetMonitorFrequency(LPDWORD lpdwFrequency) { return p->GetMonitorFrequency(lpdwFrequency); }
    WINAPI HRESULT GetScanLine(LPDWORD lpdwScanLine) { return p->GetScanLine(lpdwScanLine); }
    WINAPI HRESULT GetVerticalBlankStatus(BOOL *lpbIsInVB) { return p->GetVerticalBlankStatus(lpbIsInVB); }
    WINAPI HRESULT Initialize(GUID *lpGUID) { return p->Initialize(lpGUID); }
    WINAPI HRESULT RestoreDisplayMode() { return p->RestoreDisplayMode(); }
    WINAPI HRESULT SetCooperativeLevel(HWND hWnd, DWORD dwFlags) { return p->SetCooperativeLevel(hWnd, dwFlags); }
    WINAPI HRESULT SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP) { return p->SetDisplayMode(dwWidth, dwHeight, dwBPP); }
    WINAPI HRESULT WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent) { return p->WaitForVerticalBlank(dwFlags, hEvent); }
};

auto TrueDirectDrawCreate = &DirectDrawCreate;
HRESULT WINAPI HookDirectDrawCreate(GUID*param0,LPDIRECTDRAW*param1,IUnknown*param2)
{
    auto ret = TrueDirectDrawCreate(param0,param1,param2);
    if (FAILED(ret))
    {
        return ret;
    }

    auto obj = new HookDirectDraw();
    obj->p = *param1;
    *param1 = obj;

    return ret;
}

BOOL WINAPI DllMain(HINSTANCE /*hinstDLL*/, DWORD fdwReason, LPVOID /*lpvReserved*/)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        Mhook_SetHook(reinterpret_cast<void**>(&TrueDirectDrawCreate), reinterpret_cast<void*>(&HookDirectDrawCreate));
    }
    return TRUE;
}

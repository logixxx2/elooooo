#include <d3d11.h>
#include "../utils/vmt.h"

namespace hooks {
    void DX11::Init() {
        // Hookuj Present z u¿yciem VMT
        VMT::Hook(&oPresent, DX11Device, 17, (void*)&hkPresent);
    }

    HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
        if (gui::Menu::IsOpen()) {
            gui::Render::DrawMenu();
        }
        return oPresent(pSwapChain, SyncInterval, Flags);
    }
}
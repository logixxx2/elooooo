namespace Hooks {
    HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
        static bool init = false;
        if (!init) {
            ImGui_ImplDX11_Init(
                DX11::device,
                DX11::context
            );
            init = true;
        }

        ImGui_ImplDX11_NewFrame();
        ImGui::NewFrame();

        if (GUI::showMenu) {
            GUI::RenderMenu(); // Renderowanie menu konfiguracyjnego
        }

        ESP::Render(); // Rysowanie ESP
        ImGui::Render();

        return oPresent(pSwapChain, SyncInterval, Flags);
    }
}
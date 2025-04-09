#pragma once
#include "hooks.h"
#include "../features/aimbot.h"
#include "../features/antiaim.h"

namespace Hooks {
    bool __stdcall CreateMove(float frameTime, UserCmd* cmd) {
        static auto original = vmtClientMode->Original<CreateMoveFn>(24);
        if (!original(frameTime, cmd)) return false;

        if (cmd->commandNumber == 0) return true;

        bool sendPacket = true;

        Aimbot::Run(cmd);
        AntiAim::Run(cmd, sendPacket);

        Math::ClampAngles(cmd->viewangles);
        return false;
    }

    HRESULT __stdcall Present(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags) {
        static bool initialized = false;
        if (!initialized) {
            ImGui_ImplDX11_Init(device, context);
            initialized = true;
        }

        ImGui_ImplDX11_NewFrame();
        ImGui::NewFrame();

        if (GUI::showMenu) {
            GUI::Render();
        }

        ESP::Render();
        ImGui::Render();

        return originalPresent(swapChain, syncInterval, flags);
    }
}
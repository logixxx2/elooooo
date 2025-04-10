#include "glow.h"
#include "offset.h"
#include "memory.h"
#include <iostream>
#include <vector>

void RunGlowHack() {
    DWORD pid = Memory::GetProcessID("Counter-Strike 2");
    if (pid == 0) {
        std::cerr << "Nie znaleziono procesu CS2!" << std::endl;
        return;
    }

    HANDLE hProcess = Memory::GetProcessHandle(pid);
    if (!hProcess) {
        std::cerr << "Nie mo¿na otworzyæ procesu!" << std::endl;
        return;
    }

    try {
        DWORD localPlayer = Memory::Read<DWORD>(hProcess, Offsets::dwLocalPlayer);
        int myTeam = Memory::Read<int>(hProcess, localPlayer + Offsets::m_iTeamNum);

        for (int i = 0; i < 64; i++) {
            DWORD entity = Memory::Read<DWORD>(hProcess, Offsets::dwEntityList + i * 0x10);
            if (!entity) continue;

            int entityTeam = Memory::Read<int>(hProcess, entity + Offsets::m_iTeamNum);
            if (entityTeam == myTeam) continue;

            int glowIndex = Memory::Read<int>(hProcess, entity + Offsets::m_iGlowIndex);
            OffsetManager::UpdateGlow(hProcess, entity, glowIndex, 1.0f, 0.0f, 0.0f, 0.8f);
        }
    }
    catch (...) {
        std::cerr << "B³¹d podczas czytania pamiêci!" << std::endl;
    }

    CloseHandle(hProcess);
}
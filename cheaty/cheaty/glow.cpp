#include "glow.h"
#include "offset.h"
#include "memory.h"
#include <iostream>
#include <vector>
#include <TlHelp32.h>

void RunGlowHack() {
    DWORD pid = Memory::GetProcessID("Counter-Strike 2");
    if (pid == 0) {
        std::cerr << "[!] Nie znaleziono procesu CS2!" << std::endl;
        return;
    }

    HANDLE hProcess = Memory::GetProcessHandle(pid);
    if (!hProcess) {
        std::cerr << "[!] Nie mo¿na otworzyæ procesu!" << std::endl;
        return;
    }

    // Pobieranie adresu base client.dll
    DWORD_PTR clientBase = 0;
    MODULEENTRY32 modEntry = { 0 };
    modEntry.dwSize = sizeof(MODULEENTRY32);
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
    if (Module32First(hSnapshot, &modEntry)) {
        do {
            if (std::string(modEntry.szModule) == "client.dll") {
                clientBase = (DWORD_PTR)modEntry.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshot, &modEntry));
    }
    CloseHandle(hSnapshot);

    if (clientBase == 0) {
        std::cerr << "[!] Nie znaleziono client.dll!" << std::endl;
        CloseHandle(hProcess);
        return;
    }

    std::cout << "[+] Base address client.dll: 0x" << std::hex << clientBase << std::dec << std::endl;

    try {
        DWORD localPlayer = Memory::Read<DWORD>(hProcess, clientBase + Offsets::dwLocalPlayer);
        int myTeam = Memory::Read<int>(hProcess, localPlayer + Offsets::m_iTeamNum);

        for (int i = 0; i < 64; i++) {
            DWORD entity = Memory::Read<DWORD>(hProcess, clientBase + Offsets::dwEntityList + i * 0x10);
            if (!entity) continue;

            int entityTeam = Memory::Read<int>(hProcess, entity + Offsets::m_iTeamNum);
            if (entityTeam == myTeam) continue;

            int glowIndex = Memory::Read<int>(hProcess, entity + Offsets::m_iGlowIndex);
            OffsetManager::UpdateGlow(hProcess, entity, glowIndex, 1.0f, 0.0f, 0.0f, 0.8f); // czerwony
        }
    }
    catch (...) {
        std::cerr << "[!] B³¹d podczas czytania pamiêci!" << std::endl;
    }

    CloseHandle(hProcess);
}

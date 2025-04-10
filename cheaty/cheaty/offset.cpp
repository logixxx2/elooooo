#include "offset.h"
#include "memory.h"
#include <vector>

namespace Offsets {
    const DWORD dwLocalPlayer = 0xDEA964;
    const DWORD dwEntityList = 0x4DFFF7C;
    const DWORD dwGlowObjectManager = 0x535AA88;
    const DWORD m_iTeamNum = 0xF4;
    const DWORD m_iGlowIndex = 0x10488;
    const DWORD m_bSpotted = 0x93D;
    const DWORD m_iHealth = 0x100;
}

DWORD OffsetManager::GetGlowObjectManager(HANDLE hProcess) {
    return Memory::Read<DWORD>(hProcess, Offsets::dwGlowObjectManager);
}

std::vector<GlowObjectDefinition> OffsetManager::GetGlowObjects(HANDLE hProcess, DWORD glowManager) {
    std::vector<GlowObjectDefinition> glowObjects;
    DWORD size = Memory::Read<DWORD>(hProcess, glowManager + 0xC);

    for (DWORD i = 0; i < size; i++) {
        DWORD addr = Memory::Read<DWORD>(hProcess, glowManager + 0x4 + i * 0x38);
        GlowObjectDefinition obj = Memory::Read<GlowObjectDefinition>(hProcess, addr);
        glowObjects.push_back(obj);
    }

    return glowObjects;
}

void OffsetManager::UpdateGlow(HANDLE hProcess, DWORD entity, int glowIndex, float r, float g, float b, float a) {
    DWORD glowManager = GetGlowObjectManager(hProcess);
    DWORD glowAddress = glowManager + glowIndex * 0x38;

    Memory::Write<float>(hProcess, glowAddress + 0x8, r);
    Memory::Write<float>(hProcess, glowAddress + 0xC, g);
    Memory::Write<float>(hProcess, glowAddress + 0x10, b);
    Memory::Write<float>(hProcess, glowAddress + 0x14, a);
    Memory::Write<bool>(hProcess, glowAddress + 0x28, true);
    Memory::Write<bool>(hProcess, glowAddress + 0x29, true);
}
#pragma once
#include <vector>
#include <Windows.h>

namespace Offsets {
    extern const DWORD dwLocalPlayer;
    extern const DWORD dwEntityList;
    extern const DWORD dwGlowObjectManager;
    extern const DWORD m_iTeamNum;
    extern const DWORD m_iGlowIndex;
    extern const DWORD m_bSpotted;
    extern const DWORD m_iHealth;
}

struct GlowObjectDefinition {
    DWORD entityPtr;
    float r, g, b, a;
    uint8_t unk1[16];
    bool m_bRenderWhenOccluded;
    bool m_bRenderWhenUnoccluded;
    bool m_bFullBloom;
    uint8_t unk2[13];
};

class OffsetManager {
public:
    static DWORD GetGlowObjectManager(HANDLE hProcess);
    static std::vector<GlowObjectDefinition> GetGlowObjects(HANDLE hProcess, DWORD glowManager);
    static void UpdateGlow(HANDLE hProcess, DWORD entity, int glowIndex, float r, float g, float b, float a);
};
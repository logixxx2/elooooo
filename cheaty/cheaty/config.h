#pragma once
#pragma once

namespace Offsets {
    // Przyk³adowe offsety (aktualizuj je wed³ug hazedumper!)
    constexpr DWORD dwLocalPlayer = 0xDEA964;
    constexpr DWORD dwEntityList = 0x4DFFF7C;
    constexpr DWORD m_iTeamNum = 0xF4;
    constexpr DWORD m_iGlowIndex = 0x10488;
}

namespace Config {
    constexpr float GlowColorEnemy[4] = { 1.0f, 0.0f, 0.0f, 0.8f }; // Czerwony
    constexpr float GlowColorVisible[4] = { 0.0f, 1.0f, 0.0f, 0.8f }; // Zielony (widoczny)
}
#pragma once
#include <array>

namespace Config {
    namespace Aimbot {
        inline bool enabled = true;
        inline float fov = 5.0f;
        inline float smooth = 2.0f;
        inline bool silent = true;
    }

    namespace Visuals {
        inline bool esp = true;
        inline bool skeleton = false;
        inline std::array<float, 3> enemyColor = { 1.0f, 0.0f, 0.0f };
    }

    namespace AntiAim {
        inline bool enabled = true;
        inline float jitterRange = 45.0f;
    }

    void Save(const std::string& path);
    void Load(const std::string& path);
}
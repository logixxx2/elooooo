#pragma once

namespace Config {
    namespace Aimbot {
        inline bool enabled = true;
        inline float fov = 5.0f;
        inline float smooth = 2.0f;
    }

    namespace Visuals {
        inline bool esp = true;
        inline bool wallhack = false;
        inline float enemyColor[3] = { 1.0f, 0.0f, 0.0f };
    }

    namespace AntiAim {
        inline bool enabled = true;
        inline float speed = 45.f;
    }

    bool Save(const std::string& path);
    bool Load(const std::string& path);
}
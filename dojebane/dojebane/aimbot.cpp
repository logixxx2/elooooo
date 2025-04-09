#include "../memory.h"
#include "../config.h"

namespace Aimbot {
    Vector3 GetBestTarget(uintptr_t localPlayer) {
        Vector3 bestTarget{ 0, 0, 0 };
        float bestFov = Config::Aimbot::fov;

        for (int i = 0; i < 64; i++) {
            uintptr_t player = Memory::Read<uintptr_t>(gameModule + offsets::entityList + i * 0x10);
            if (!player || player == localPlayer) continue;

            Vector3 headPos = Memory::Read<Vector3>(player + offsets::boneMatrix + 8 * 0x20);
            float fov = Math::GetFOV(localPlayer, headPos);

            if (fov < bestFov) {
                bestTarget = headPos;
                bestFov = fov;
            }
        }
        return bestTarget;
    }

    void Run(UserCmd* cmd) {
        if (!Config::Aimbot::enabled) return;

        uintptr_t localPlayer = Memory::Read<uintptr_t>(gameModule + offsets::localPlayer);
        Vector3 target = GetBestTarget(localPlayer);

        if (!target.IsZero()) {
            QAngle angles = Math::CalculateAngle(
                Memory::Read<Vector3>(localPlayer + offsets::viewOffset),
                target
            );
            cmd->viewangles = angles;
        }
    }
}
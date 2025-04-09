#include "antiaim.h"
#include "../config.h"

float AntiAim::GetRandomYaw(float baseYaw) {
    static float lastYaw = 0.f;
    lastYaw += (rand() % 60 - 30); // Losowa zmiana od -30 do +30
    return baseYaw + lastYaw;
}

void AntiAim::Run(UserCmd* cmd, bool& sendPacket) {
    if (!Config::AntiAim::enabled) return;

    static float realYaw = cmd->viewangles.y;

    if (sendPacket) {
        // Fake angle
        cmd->viewangles.y = GetRandomYaw(realYaw + 180.f);
        cmd->viewangles.x = 89.f; // Pitch up
    }
    else {
        // Real angle
        cmd->viewangles.y = GetRandomYaw(realYaw);
        cmd->viewangles.x = -89.f; // Pitch down
    }

    sendPacket = !sendPacket;
}
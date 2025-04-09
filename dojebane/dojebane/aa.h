#pragma once
#include "../sdk.h"

namespace AntiAim {
    void Run(UserCmd* cmd, bool& sendPacket);
    float GetRandomYaw(float baseYaw);
}
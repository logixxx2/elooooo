#pragma once
#include "../sdk.h"

namespace Aimbot {
    void Run(UserCmd* cmd);
    Vector3 CalculateBestTarget();
    Vector3 PredictMovement(const Vector3& targetPos, const Vector3& targetVel);
}
#include "../../hooks/entity.h"
#include "../../utils/math.h"

namespace features {
    void Aimbot::Run() {
        if (!config::aimbotEnabled) return;

        Vector3 target = Entity::GetClosestEnemy();
        if (target.IsValid()) {
            math::AimAt(target);
        }
    }
}
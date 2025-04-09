#include "../gui.h"
#include "../memory.h"

namespace ESP {
    void Render() {
        if (!Config::Visuals::esp) return;

        for (int i = 0; i < 64; i++) {
            uintptr_t player = Memory::Read<uintptr_t>(gameModule + offsets::entityList + i * 0x10);
            if (!player) continue;

            Vector3 feetPos = Memory::Read<Vector3>(player + offsets::origin);
            Vector3 headPos = feetPos + Vector3{ 0, 0, 72.f }; // Przybli¿ona wysokoœæ

            Vector2 screenFeet, screenHead;
            if (Math::WorldToScreen(feetPos, screenFeet) &&
                Math::WorldToScreen(headPos, screenHead)) {

                float height = screenHead.y - screenFeet.y;
                float width = height / 2.f;

                GUI::DrawBox(screenHead.x - width / 2, screenHead.y,
                    width, height,
                    Config::Visuals::enemyColor);
            }
        }
    }
}
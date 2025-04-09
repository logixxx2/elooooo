namespace Wallhack {
    void Apply() {
        if (!Config::Visuals::wallhack) return;

        for (int i = 0; i < 64; i++) {
            uintptr_t player = Memory::Read<uintptr_t>(gameModule + offsets::entityList + i * 0x10);
            if (!player) continue;

            // Zmiana materia³u modelu na "wireframe"
            uintptr_t renderable = Memory::Read<uintptr_t>(player + 0x4);
            uintptr_t model = Memory::Read<uintptr_t>(renderable + 0x20);
            Memory::Write<int>(model + 0x58, 2); // 2 = Wireframe
        }
    }
}
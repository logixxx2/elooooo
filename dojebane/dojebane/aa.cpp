namespace AntiAim {
    void FakeAngles(UserCmd* cmd, bool& sendPacket) {
        if (!Config::AntiAim::enabled) return;

        static float fakeYaw = 0.f;
        fakeYaw += Config::AntiAim::speed;

        if (sendPacket) {
            cmd->viewangles.y = fakeYaw; // Tylko serwer widzi ten k¹t
            sendPacket = false;
        }
        else {
            cmd->viewangles.y += 180.f;  // Lokalny k¹t
            sendPacket = true;
        }
    }
}
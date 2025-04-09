#include "gui.h"
#include "config.h"

void GUI::Render() {
    if (!showMenu) return;

    ImGui::Begin("HVH Menu");
    ImGui::Checkbox("Aimbot", &Config::Aimbot::enabled);
    ImGui::SliderFloat("FOV", &Config::Aimbot::fov, 1.0f, 180.0f);
    ImGui::End();
}
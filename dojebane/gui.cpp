#include <imgui.h> // Dodaj nag��wek ImGui
#include "gui.h"
#include "config.h"

// Dodaj definicj� zmiennej showMenu jako cz�onka klasy
bool GUI::showMenu = false; // Je�li to zmienna statyczna, zdefiniuj j� tutaj

void GUI::Render() {
    if (!showMenu) return;
    ImGui::Begin("HVH Menu");
    ImGui::Checkbox("Aimbot", &Config::Aimbot::enabled);
    ImGui::SliderFloat("FOV", &Config::Aimbot::fov, 1.0f, 180.0f);
    ImGui::End();
}

// Dodaj funkcj� do prze��czania menu
void GUI::Toggle() {
    showMenu = !showMenu;
}
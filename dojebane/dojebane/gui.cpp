#include <imgui.h> // Dodaj nag³ówek ImGui
#include "gui.h"
#include "config.h"

// Dodaj definicjê zmiennej showMenu jako cz³onka klasy
bool GUI::showMenu = false; // Jeœli to zmienna statyczna, zdefiniuj j¹ tutaj

void GUI::Render() {
    if (!showMenu) return;
    ImGui::Begin("HVH Menu");
    ImGui::Checkbox("Aimbot", &Config::Aimbot::enabled);
    ImGui::SliderFloat("FOV", &Config::Aimbot::fov, 1.0f, 180.0f);
    ImGui::End();
}

// Dodaj funkcjê do prze³¹czania menu
void GUI::Toggle() {
    showMenu = !showMenu;
}
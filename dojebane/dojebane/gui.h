#pragma once
#include <imgui.h> // Dodaj nag��wek ImGui

class GUI {
public:
    static void Render();
    static void Toggle();

private:
    static bool showMenu;
};
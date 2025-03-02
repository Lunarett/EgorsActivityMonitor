#include <imgui.h>
#include "ImGuiLayer.h"
#include "Log.h"
#include "Renderer.h"
#include "Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Log::Init();

    Window window(L"Egors Activity Monitor", 1280, 720);
    Renderer renderer(window.GetHWND());
    ImGuiLayer imguiLayer(window.GetHWND(), renderer.GetDevice(), renderer.GetDeviceContext());

    while (window.ProcessMessages())
    {
        renderer.Clear(0.1f, 0.1f, 0.1f, 1.0f);

        imguiLayer.Begin();

        // Test ImGui Window
        ImGui::ShowDemoWindow();

        imguiLayer.End();
        imguiLayer.Render();

        renderer.Present();
    }

    return 0;
}
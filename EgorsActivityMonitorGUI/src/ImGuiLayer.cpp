#include "ImGuiLayer.h"
#include "imgui.h"
#include "backends/imgui_impl_dx11.h"
#include "backends/imgui_impl_win32.h"

// Forward declare Win32 function needed by ImGui
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

ImGuiLayer::ImGuiLayer(HWND hWnd, ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
    InitImGui(hWnd, device, deviceContext);
}

ImGuiLayer::~ImGuiLayer()
{
    CleanupImGui();
}

void ImGuiLayer::InitImGui(HWND hWnd, ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hWnd);
    ImGui_ImplDX11_Init(device, deviceContext);

    LOG_INFO("ImGui initialized successfully.");
}

void ImGuiLayer::CleanupImGui()
{
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    LOG_INFO("ImGui cleaned up successfully.");
}

void ImGuiLayer::Begin()
{
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::End()
{
    ImGui::Render();
}

void ImGuiLayer::Render()
{
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
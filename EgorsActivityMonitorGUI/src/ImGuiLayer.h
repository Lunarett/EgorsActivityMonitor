#pragma once

#include <d3d11.h>
#include <Windows.h>
#include "Renderer.h"
#include "Log.h"

// Forward declare ImGui functions
struct ImGuiContext;

class ImGuiLayer
{
public:
    ImGuiLayer(HWND hWnd, ID3D11Device* device, ID3D11DeviceContext* deviceContext);
    ~ImGuiLayer();

    void Begin();
    void End();
    void Render();

private:
    void InitImGui(HWND hWnd, ID3D11Device* device, ID3D11DeviceContext* deviceContext);
    void CleanupImGui();
};
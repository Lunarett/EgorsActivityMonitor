#pragma once

#include <d3d11.h>
#include <memory>
#include <wrl/client.h>
#include "Log.h"

class Renderer
{
public:
    Renderer(HWND hWnd);
    ~Renderer();

    void Clear(float r, float g, float b, float a);
    void Present();

    ID3D11Device* GetDevice() const { return m_Device.Get(); }
    ID3D11DeviceContext* GetDeviceContext() const { return m_DeviceContext.Get(); }

private:
    void InitD3D(HWND hWnd);
    void CleanupD3D();

    Microsoft::WRL::ComPtr<ID3D11Device> m_Device;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_DeviceContext;
    Microsoft::WRL::ComPtr<IDXGISwapChain> m_SwapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_RenderTargetView;
};
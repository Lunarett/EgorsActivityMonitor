#include "Renderer.h"

Renderer::Renderer(HWND hWnd)
{
    InitD3D(hWnd);
}

Renderer::~Renderer()
{
    CleanupD3D();
}

void Renderer::InitD3D(HWND hWnd)
{
    DXGI_SWAP_CHAIN_DESC scd = {};
    scd.BufferCount = 1;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = hWnd;
    scd.SampleDesc.Count = 1;
    scd.Windowed = TRUE;
    scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    D3D_FEATURE_LEVEL featureLevel;
    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        createDeviceFlags,
        featureLevels,
        1,
        D3D11_SDK_VERSION,
        &scd,
        &m_SwapChain,
        &m_Device,
        &featureLevel,
        &m_DeviceContext
    );

    if (FAILED(hr))
    {
        LOG_ERROR("Failed to create DirectX 11 device and swap chain. HRESULT: {0}", hr);
        return;
    }

    Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;
    hr = m_SwapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
    if (FAILED(hr))
    {
        LOG_ERROR("Failed to get back buffer. HRESULT: {0}", hr);
        return;
    }

    hr = m_Device->CreateRenderTargetView(backBuffer.Get(), nullptr, &m_RenderTargetView);
    if (FAILED(hr))
    {
        LOG_ERROR("Failed to create render target view. HRESULT: {0}", hr);
        return;
    }

    m_DeviceContext->OMSetRenderTargets(1, m_RenderTargetView.GetAddressOf(), nullptr);
    LOG_INFO("DirectX 11 initialized successfully.");
}

void Renderer::CleanupD3D()
{
    if (m_DeviceContext) m_DeviceContext->ClearState();
}

void Renderer::Clear(float r, float g, float b, float a)
{
    const float color[4] = { r, g, b, a };
    m_DeviceContext->ClearRenderTargetView(m_RenderTargetView.Get(), color);
}

void Renderer::Present()
{
    m_SwapChain->Present(1, 0);
}
#pragma once

#include <Windows.h>
#include <string>

class Window
{
public:
    Window(const std::wstring& title, int width, int height);
    ~Window();

    bool ProcessMessages();

    HWND GetHWND() const { return m_hWnd; }

private:
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    HWND m_hWnd;
};
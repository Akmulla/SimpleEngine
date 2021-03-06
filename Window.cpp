#include "Window.h"

Window* Window::instance = nullptr;

Window::Window(HINSTANCE hInstance) 
{
	const auto winClassName = "SimpleExampleWindowClass";
	keyboard.keystates.set();
	WNDCLASSEX wc = { };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = winClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(
		0,
		winClassName,
		"MyWindow",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200,
		200,
		640,
		480,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);
	//Graphics g(hWnd);
	gfx = new Graphics(hWnd);
	instance = this;
	ShowWindow(hWnd, SW_SHOW);
}

void Window::EndFrame()
{
	gfx->EndFrame();
}

void Window::ClearBuffer(float r, float g, float b)
{
	gfx->ClearBuffer(r, g, b);
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return instance->HandleMessage(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK Window::HandleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_KEYDOWN:
			keyboard.SetKeyPressState(static_cast<unsigned char>(wParam));
			break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
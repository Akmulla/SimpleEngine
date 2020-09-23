#pragma once
#include <d3d11.h>
#include "Keyboard.h"

class Window
{
public:
	Window(HINSTANCE hInstance);
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	Keyboard keyboard;
	HWND hWnd;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};
#pragma once
#include <d3d11.h>

class Graphics
{
public:
	void InitWindow(HWND& hWnd, HINSTANCE hInstance, WNDPROC WndProc);
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
};
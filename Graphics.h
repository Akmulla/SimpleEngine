#pragma once
#include <Windows.h>
#include <d3d11.h>

class Graphics
{
public:
	Graphics( HWND hWnd );
	void EndFrame();
	void ClearBuffer(float red, float green, float blue);
	void DrawTriangle();
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* pTarget = nullptr;
};
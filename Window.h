#pragma once
#include <d3d11.h>
#include "Keyboard.h"
#include <string>
#include <sstream>
#include "Graphics.h"

class Window
{
public:
	Window(HINSTANCE hInstance);
	static Window* instance;
	HWND hWnd;
	Graphics* gfx;
	void EndFrame();
	void ClearBuffer(float r, float g, float b);
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	Keyboard keyboard;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK HandleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};
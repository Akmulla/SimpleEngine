#include <Windows.h>
#include <string>
#include <sstream>
#include "Window.h"
#include "Time.h"

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Window window(hInstance);
	Time time;

	MSG msg;
	HWND hWnd = window.hWnd;
	while (true)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return msg.wParam;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		time.Tick();
		double dt = time.GetDt();
		window.DrawGraphics();
		//std::ostringstream oss;
		//oss << "(" << dt << ")";
		//SetWindowText(window.hWnd, oss.str().c_str());
	}
}
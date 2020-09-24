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
	BOOL gResult;
	while ( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		time.Tick();
		double dt = time.GetDt();
		std::ostringstream oss;
		oss << "(" << dt << ")";
		SetWindowText(window.hWnd, oss.str().c_str());
	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}
#pragma once
#include <chrono>
#include <iostream>

class Time
{
public :
	Time();
	void Tick();
	double GetDt();
	double GetTime();
private:
	std::chrono::steady_clock::time_point lastTick;
	std::chrono::steady_clock::time_point firstTick;
	double dt;
};
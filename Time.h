#pragma once
#include <chrono>
#include <iostream>

class Time
{
public :
	Time();
	void Tick();
	double GetDt();
private:
	std::chrono::steady_clock::time_point lastTick;
	double dt;
};
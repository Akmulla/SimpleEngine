#include "Time.h"

Time::Time()
{
    lastTick = std::chrono::steady_clock::now();
    dt = 0.0;
}

void Time::Tick()
{
    std::chrono::steady_clock::time_point t = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t - lastTick);
    dt = time_span.count();
    lastTick = t;
}

double Time::GetDt()
{
    return dt;
}
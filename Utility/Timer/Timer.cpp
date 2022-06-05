#include "Timer.h"

void Timer::startTimer()
{
    LARGE_INTEGER li;

    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double Timer::stopTimer()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
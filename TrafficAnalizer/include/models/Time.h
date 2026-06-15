#pragma once
#include <iostream>
#include <string>

int timeConvertion(int hours, int minutes, int seconds);

class Time
{
    // --------Variables--------
private:
    int timeInSeconds;

    // --------Constructors--------
public:
    Time(int hours, int minutes, int seconds) : timeInSeconds{ timeConvertion(hours, minutes, seconds) } {};
    Time(int timeInSeconds) : timeInSeconds{ timeInSeconds } {};

    // --------Methods--------
    std::string GetTime() const { return std::to_string(GetHour()) + ":" + std::to_string(GetMinute()) + ":" + std::to_string(GetSecond()); };

    int GetHour() const { return timeInSeconds / 3600; }
    int GetMinute() const { return (timeInSeconds % 3600) / 60; }
    int GetSecond() const { return timeInSeconds % 60; }

};

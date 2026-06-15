#pragma once
#include <iostream>
#include <string>

unsigned __int64 timeConvertion(int hours, int minutes, int seconds);

class Time
{
    // --------Variables--------
private:
    unsigned __int64 timeInSeconds;

    // --------Constructors--------
public:
    Time(int hours, int minutes, int seconds) : timeInSeconds{ timeConvertion(hours, minutes, seconds) } {};
    Time(unsigned __int64 timeInSeconds) : timeInSeconds{ timeInSeconds } {};

    // --------Methods--------
    std::string GetTime() const { return std::to_string(GetHour()) + ":" + std::to_string(GetMinute()) + ":" + std::to_string(GetSecond()); };

    int GetHour() const { return timeInSeconds / 3600; }
    int GetMinute() const { return (timeInSeconds % 3600) / 60; }
    int GetSecond() const { return timeInSeconds % 60; }

	// --------Operators--------
    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;

	bool operator>=(const Time& other) const { return timeInSeconds >= other.timeInSeconds; }
	bool operator<=(const Time& other) const { return timeInSeconds <= other.timeInSeconds; }
	bool operator>(const Time& other) const { return timeInSeconds > other.timeInSeconds; }
	bool operator<(const Time& other) const { return timeInSeconds < other.timeInSeconds; }
	bool operator==(const Time& other) const { return timeInSeconds == other.timeInSeconds; }
	bool operator!=(const Time& other) const { return timeInSeconds != other.timeInSeconds; }
};

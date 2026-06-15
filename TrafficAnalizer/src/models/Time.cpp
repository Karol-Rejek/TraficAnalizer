#include "../include/models/Time.h"

unsigned __int64 timeConvertion(int hours, int minutes, int seconds)
{
    return hours * 3600 + minutes * 60 + seconds;
}

Time Time::operator+(const Time& other) const
{
    return Time(timeInSeconds + other.timeInSeconds);
}

Time Time::operator-(const Time& other) const
{
    return Time(timeInSeconds - other.timeInSeconds);
}

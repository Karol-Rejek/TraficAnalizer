#pragma once
#include <iostream>
#include <string>

bool isLeapYear(int year);

class Date
{
    // --------Variables--------
private:
    int day;
    int month;
    int year;

    // --------Constructors--------
public:
    Date(int day, int month, int year) : day{ day }, month{ month }, year{ year } {};

    // --------Methods--------
private:
    bool isLastDayOfMonth();

public:
    void IncreaseDay();

    // --------Getters--------
public:
    std::string GetDate();
    int GetDay() const { return day; }
    int GetMonth() const { return month; }
    int GetYear() const { return year; }
};

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

struct TimeStamp
{
public:
    Date day;
    Time start;
    Time end;
};
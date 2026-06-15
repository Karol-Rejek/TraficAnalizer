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
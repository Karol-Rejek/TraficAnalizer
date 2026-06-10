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
    std::string getDate();
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

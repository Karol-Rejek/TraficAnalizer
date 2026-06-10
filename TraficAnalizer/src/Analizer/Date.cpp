#include "Date.h"

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }

}

bool Date::isLastDayOfMonth()
{
    switch (month)
    {
    case 1: // January
    case 3: // March
    case 5: // May
    case 7: // July
    case 8: // August
    case 10: // October
    case 12: // December
        if (day == 31)
        {
            return true;
        }
        break;
    case 4: // April
    case 6: // June
    case 9: // September
    case 11: // November
        if (day == 30)
        {
            return true;
        }
        break;
    case 2: // February
        if (isLeapYear(year))
        {
            if (day == 29)
            {
                return true;
            }
        }
        else
        {
            if (day == 28)
            {
                return true;
            }
        }
        break;
    default:
        return false;
    }

}

void Date::IncreaseDay()
{
    if (day == isLastDayOfMonth())
    {
        if (month == 12)
        {
            day = 1;
            month = 1;
            year++;
        }
        else
        {
            day = 1;
            month++;
        }
    }
    else
    {
        day++;
    }

}

std::string Date::getDate()
{
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}

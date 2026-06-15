#include "../include/models/Time.h"

int timeConvertion(int hours, int minutes, int seconds)
{
    return hours * 3600 + minutes * 60 + seconds;
}
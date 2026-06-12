#include "AnalizedRezults.h"

std::string AnalizedRezults::GetMeserment()
{
	return "Day: " + meserment.day.GetDate() + "\nStart: " + meserment.start.GetTime() + "\nEnd: " + meserment.end.GetTime() + "\n";
}

void AnalizedRezults::SetMeserment(Date day, Time start, Time end)
{
	meserment.day = day;
	meserment.start = start;
	meserment.end = end;
}

#include "../include/core/AnalizedResults.h"

std::string AnalizedRezults::GetMeserment()
{
	return "\n Day: " + meserment.day.GetDate() + "\n Start: " + meserment.start.GetTime() + "\n End: " + meserment.end.GetTime() + "\n";
}

void AnalizedRezults::SetMeserment(Date day, Time start, Time end)
{
	meserment.day = day;
	meserment.start = start;
	meserment.end = end;
}

std::string AnalizedRezults::TimeOfMeserment()
{
	Time timeOfMeserment = meserment.end - meserment.start;
	return " Time of meserment: " + timeOfMeserment.GetTime() + "\n";
}

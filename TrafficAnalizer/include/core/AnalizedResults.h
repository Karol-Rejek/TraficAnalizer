#pragma once
#include "../models/TrafficSnapshot.h"

class AnalizedRezults
{
	// --------Variables--------
private:
	TimeStamp meserment;
	int sumOfObjects;

	// --------Constructors--------
public:
	AnalizedRezults(Date dayMeserment, Time statMeserment, Time endMeserment, int sumOfObjects) : meserment{ dayMeserment, statMeserment, endMeserment }, sumOfObjects{ sumOfObjects } {};

	// --------Methods--------
	std::string GetMeserment();
	int GetSumOfObjects() const { return sumOfObjects; }
	void SetMeserment(Date day, Time start, Time end);

	std::string TimeOfMeserment();
};


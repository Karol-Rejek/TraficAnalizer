#pragma once
#include <iostream>
#include <vector>

#include "Date.h"
#include "Time.h"

struct TimeStamp
{
public:
	Date day;
	Time start;
	Time end;
};

class TrafficSnapshot
{
	// --------Variables--------
private:
	int id;
	int amountOfObjects;
	TimeStamp timeStamp;
	//std::vector<int> ObjectsInTime;

	// --------Constructors--------
public:
	TrafficSnapshot(int id, int amountOfObjects, Date day, Time start, Time end) : id{ id }, amountOfObjects{ amountOfObjects }, timeStamp{ day, start, end } {};

	// --------Methods--------
	int GetAmountOfObjects() const { return amountOfObjects; }
	TimeStamp GetTimeStamp() const { return timeStamp; }
};
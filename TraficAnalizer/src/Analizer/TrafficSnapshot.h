#pragma once
#include <iostream>
#include <vector>

#include "Date.h"

struct TimeStamp
{
	Date startMeserment;
	Date endMeserment;
};

class TrafficSnapshot
{
private:
	int id;
	int amountOfObjects;
	std::vector<int> ObjectsInTime;
	
public:

	
};

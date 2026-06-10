// TraficAnalizer.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "TraficAnalizer.h"
#include "src/Analizer/TrafficSnapshot.h"

/*
time = 8
amount = [1, 4, 6, 2, 9, 3, 2, 5]
numberOfSamples = 3
maxAmountOfObjects = 14
przechodzi 6 razy
*/

int display(std::map<int,int> m, int c)
{
	std::cout << "Number of times: " << c << "\n";
	for (int i = 1; i <= m.size(); i++)
	{
		std::cout << m[i] << "\n";
	}
	return 0;
}

int Analize(TrafficSnapshot trafficSnapshot, int numberOfSamples, int maxAmountOfObjects)
{
	int counter = 0;
	std::map<int, int> sumOfObjectsInTime;

	/*for (int i = 0; i <= time - numberOfSamples; i++)
	{
		int sum = 0;
		for (int j = i; j < i + numberOfSamples; j++)
		{
			sum += amountOfObjects[j];
		}

		if (sum >= maxAmountOfObjects)
		{
			sumOfObjectsInTime.insert({i+1, sum });
			counter++;
		}
	}*/

	return display(sumOfObjectsInTime, counter);
}


/*
Objekt to analize
time - in h
amountOfObjects - in time
type of object - collection with objects in time
*/

int main()
{
	int time = 8;
	std::vector<int> amountOfTraficObjectsInTime = { 1, 4, 6, 2, 9, 3, 2, 5};
	int numberOfSamples = 3;
	int maxAmountOfObjects = 14;

	std::cout << Analize(time, amountOfTraficObjectsInTime, numberOfSamples, maxAmountOfObjects) << std::endl;
	return 0;
}

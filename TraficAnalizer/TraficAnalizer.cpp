// TraficAnalizer.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "TraficAnalizer.h"
#include "src/Analizer/TrafficSnapshot.h"
#include "src/Analizer/AnalizedRezults.h"

void display(AnalizedRezults rez)
{
	std::cout << "Meserment: " << rez.GetMeserment() << " Sum of objects: " << rez.GetSumOfObjects() << "\n";
}

void display(std::vector<AnalizedRezults> collectionToDisplay)
{
	for (auto i : collectionToDisplay)
	{
		display(i);
	}
}

std::vector<AnalizedRezults> Analize(std::vector<TrafficSnapshot> trafficSnapshotsCollection, int numberOfSamples, int maxAmountOfObjects)
{
	int counter = 0;
	std::vector<AnalizedRezults> rezults;

	for (int i = 0; i <= trafficSnapshotsCollection.size() - numberOfSamples; i++)
	{
		int sum = 0;
		for (int j = i; j < i + numberOfSamples; j++)
		{
			sum += trafficSnapshotsCollection[j].GetAmountOfObjects();
		}

		if (sum >= maxAmountOfObjects)
		{
			AnalizedRezults rez{ trafficSnapshotsCollection[i].GetTimeStamp().day, trafficSnapshotsCollection[i].GetTimeStamp().start , trafficSnapshotsCollection[i + numberOfSamples - 1].GetTimeStamp().end, sum};
			rezults.push_back(rez);
			counter++;
		}
		std::cout << "Loop: " << i << "\n";
	}
	std::cout << "Counter: " << counter << "\n";
	return rezults;
}

// I need create a unit tests to test this program instead of this
int main()
{
	display(Analize({ TrafficSnapshot(1, 10, Date(1, 1, 2024), Time(0, 0, 0), Time(0, 15, 0)),
				 TrafficSnapshot(2, 20, Date(1, 1, 2024), Time(0, 15, 0), Time(0, 30, 0)),
				 TrafficSnapshot(3, 30, Date(1, 1, 2024), Time(0, 30, 0), Time(0, 45, 0)),
				 TrafficSnapshot(4, 40, Date(1, 1, 2024), Time(0, 45, 0), Time(1, 0, 0)),
				 TrafficSnapshot(5, 50, Date(1, 1, 2024), Time(1, 0, 0), Time(1, 15, 0)) },
		3,
		90));
	return 0;
}

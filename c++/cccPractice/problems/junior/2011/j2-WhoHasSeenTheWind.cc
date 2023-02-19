#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int humidity = 0;
	int maxWaitTime = 0;
	cin >> humidity >> maxWaitTime;
	int altitude = 0;

	for (int hours = 1; hours < maxWaitTime; hours++)
	{
		altitude = -6 * pow(hours, 4) + humidity * pow(hours, 3) + 2 * pow(hours, 2) + hours;
		if (altitude <= 0)
		{
			cout << "The balloon first touches ground at hour:" << endl;
			cout << hours << endl;
			break;
		}
	}

	if (altitude > 0)
	{
		cout << "The balloon does not touch ground in the given time.";
	}
}

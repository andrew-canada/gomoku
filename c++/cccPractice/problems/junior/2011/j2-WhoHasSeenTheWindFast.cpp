#include <stdio.h>

int main()
{
	int humidity, maxWaitTime;
	int timeWaited = 1;
	int altitude;
	scanf("%d%d", &humidity, &maxWaitTime);

	while (timeWaited < maxWaitTime)
	{
		altitude = (-6 * timeWaited * timeWaited * timeWaited * timeWaited) +
				   (humidity * timeWaited * timeWaited * timeWaited) +
				   (2 * timeWaited * timeWaited) + timeWaited;
		if (altitude <= 0)
		{
			puts("The balloon first touches ground at hour:\n");
			printf("%d", timeWaited);
			return 0;
		}
		timeWaited += 1;
	}
	puts("The balloon does not touch ground in the given time.");
}
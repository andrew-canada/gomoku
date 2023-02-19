#include <iostream>
using namespace std;

int main()
{
	int input[2][2];
	int nF, nB, bF, bB;
	int total;

	cin >> input[0][0];
	cin >> input[0][1];
	cin >> input[1][0];
	cin >> input[1][1];
	cin >> total;

	int remainder, completeGroups, walkedDistance;
	int totalDistance[2];

	for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
	{
		int totalForEach = input[i][0] + input[i][1];
		int diff = input[i][0] - input[i][1];
		remainder = total % (totalForEach);
		completeGroups = total / (totalForEach);
		walkedDistance = diff;

		if (remainder == 0)
		{
			totalDistance[i] = completeGroups * walkedDistance;
		}
		//else if (remainder <= nF)
		else if (remainder <= input[i][0])
		{
			totalDistance[i] = completeGroups * walkedDistance + remainder;
		}
		else
		{
			//totalDistance[i] = completeGroups * walkedDistance + nF - (remainder - nF);
			totalDistance[i] = completeGroups * walkedDistance + input[i][0] - (remainder - input[i][0]);
		}
	}

	if (totalDistance[0] > totalDistance[1])
	{
		cout << "Nikky";
	}
	else if (totalDistance[1] > totalDistance[0])
	{
		cout << "Byron";
	}
	else
	{
		cout << "Tied";
	}

	return 0;
}

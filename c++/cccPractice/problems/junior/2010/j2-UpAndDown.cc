#include <iostream>
using namespace std;

int main()
{

	int nikkyFront, nikkyBack, byronFront, byronBack;
	int totalSteps;
	int nikkyDist, byronDist;

	cin >> nikkyFront;
	cin >> nikkyBack;
	cin >> byronFront;
	cin >> byronBack;
	cin >> totalSteps;

	if (totalSteps % (nikkyFront + nikkyBack) == 0)
	{
		nikkyDist = (totalSteps / (nikkyFront + nikkyBack)) * (nikkyFront - nikkyBack);
	}
	// else the steps arent divisible
	else
	{
		int groups = totalSteps / (nikkyFront + nikkyBack);
		nikkyDist = groups * (nikkyFront - nikkyBack);
		int remain = totalSteps - groups * (nikkyFront + nikkyBack);
		while (remain <= nikkyFront && remain >= 1)
		{
			nikkyDist++;
			remain--;
		}
		if (remain > nikkyFront)
		{
			nikkyDist += nikkyFront;
			nikkyDist -= (remain - nikkyFront);
		}
	}

	if (totalSteps % (byronFront + byronBack) == 0)
	{
		byronDist = (totalSteps / (byronFront + byronBack)) * (byronFront - byronBack);
	}
	// else the steps arent divisible
	else
	{
		int groups = totalSteps / (byronFront + byronBack);
		nikkyDist = groups * (byronFront - byronBack);
		int remain = totalSteps - groups * (byronFront + byronBack);
		while (remain <= byronFront && remain >= 1)
		{
			byronDist++;
			remain--;
		}
		if (remain > byronFront)
		{
			byronDist += byronFront;
			byronDist -= (remain - byronFront);
		}
	}

	if (nikkyDist > byronDist)
	{
		cout << "Nikky";
	}
	else if (byronDist > nikkyDist)
	{
		cout << "Byron";
	}
	else
	{
		cout << "Tied";
	}
	return 0;
}

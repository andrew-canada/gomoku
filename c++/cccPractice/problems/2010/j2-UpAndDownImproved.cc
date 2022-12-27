#include <iostream>
using namespace std;

int main()
{
	int nF, nB, bF, bB;
	int total;

	cin >> nF;
	cin >> nB;
	cin >> bF;
	cin >> bB;
	cin >> total;

	int remainderN = total % (nF + nB);
	int completeGroupsN = total / (nF + nB);
	int walkedDistanceN = nF - nB;
	int distN = 0;

	if (remainderN == 0)
	{
		distN = completeGroupsN * walkedDistanceN;
	}
	else if (remainderN <= nF)
	{
		distN = completeGroupsN * walkedDistanceN + remainderN;
	}
	else
	{
		distN = completeGroupsN * walkedDistanceN + nF - (remainderN - nF);
	}

	int remainderB = total % (bF + bB);
	int completeGroupsB = total / (bF + bB);
	int walkedDistanceB = bF - bB;
	int distB = 0;
	if (remainderB == 0)
	{
		distB = completeGroupsB * walkedDistanceB;
	}
	else if (remainderB <= bF)
	{
		distB = completeGroupsB * walkedDistanceB + remainderB;
	}
	else
	{
		distB = completeGroupsB * walkedDistanceB + bF - (remainderB - bF);
	}

	if (distN > distB)
	{
		cout << "Nikky";
	}
	else if (distB > distN)
	{
		cout << "Byron";
	}
	else
	{
		cout << "Tied";
	}

	return 0;
}

#include <iostream>
#include <list>
using namespace std;

int main()
{
	int numberOfTerms;
	int *differenceArray;
	list<int> output;
	int num1, num2;
	int difference;
	int patternLength;
	do
	{
		cin >> numberOfTerms;
		if (numberOfTerms == 0)
		{
			for (int lengths : output)
			{
				cout << lengths << endl;
			}
			return 0;
		}

		if (numberOfTerms == 1)
		{
			output.push_back(0);
		}

		if (numberOfTerms == 2)
		{
			output.push_back(1);
		}

		differenceArray = new int[numberOfTerms - 1];
		cin >> num1;
		for (int i = 0; i < numberOfTerms - 1; i++)
		{
			cin >> num2;
			difference = num2 - num1;
			differenceArray[i] = difference;
			num1 = num2;
		}

		int i = 0, tempPatternLength = 0;
		bool foundFirstMatch = false, isTempPatternLengthSet = false;
		for (int j = 1; j < numberOfTerms - 1; j++)
		{
			if (differenceArray[i] == differenceArray[j])
			{
				i += 1;
				foundFirstMatch = true;
				if (!isTempPatternLengthSet)
				{
					tempPatternLength = j;
					isTempPatternLengthSet = true;
				}
			}
			else if (foundFirstMatch)
			{
				isTempPatternLengthSet = false;
				foundFirstMatch = false;
				tempPatternLength = 0;
				i = 0;
				j -= 1;
			}
			if (j == numberOfTerms - 2 && tempPatternLength == 0)
			{
				output.push_back(numberOfTerms - 1);
			}
			else if (j == numberOfTerms - 2 && tempPatternLength != 0)
			{
				output.push_back(tempPatternLength);
			}
		}

	} while (numberOfTerms != 0);

	return 0;
}

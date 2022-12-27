#include <iostream>
using namespace std;

int recursiveSum(int lowerNumber, int upperNumber)
{
	if (lowerNumber == upperNumber)
	{
		return upperNumber;
	}
	return lowerNumber + recursiveSum(lowerNumber + 1, upperNumber);
}

int main()
{
	int lowerNumber, upperNumber;
	int sum = 0;
	cout << "Enter a number: ";
	cin >> lowerNumber;
	cout << endl;
	cout << "Enter another number: ";
	cin >> upperNumber;
	for (int i = lowerNumber; i <= upperNumber; i++)
	{
		sum += i;
	}
	cout << endl;
	cout << "Non-recursive sum: " << sum << endl;
	cout << recursiveSum(lowerNumber, upperNumber);
}

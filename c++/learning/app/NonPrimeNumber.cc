#include <iostream>
using namespace std;

bool isNotPrime(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;
	cout << (isNotPrime(number) ? "Not Prime" : "Prime");
	return 0;
}

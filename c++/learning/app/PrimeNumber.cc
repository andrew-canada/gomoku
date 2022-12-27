#include <iostream>
using namespace std;

bool isPrime(int number);

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;
	cout << (isPrime(number) ? "Prime" : "Not Prime") << endl;
	return 0;
}

bool isPrime(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

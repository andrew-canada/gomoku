#include <iostream>
using namespace std;

bool isPrime(int number, int i = 2)
{
	if (number <= 2)
	{
		return ((number == 2) ? true : false);
	}
	if (number % i == 0)
	{
		return false;
	}
	if (i == number - 1)
	{
		return true;
	}
	return isPrime(number, i + 1);
}

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;
	if (isPrime(number))
	{
		cout << endl
			 << "Prime";
	}
	else
	{
		cout << endl
			 << "Not prime";
	}
	return 0;
}

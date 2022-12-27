#include <iostream>
using namespace std;

int recursiveFactorial(int number)
{
	if (number == 1)
	{
		return 1;
	}
	return number * recursiveFactorial(number - 1);
}

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;
	cout << recursiveFactorial(number);
	return 0;
}

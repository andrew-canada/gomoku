#include <iostream>
using namespace std;

int fibonacci(int patternPlace)
{
	if (patternPlace == 1 || patternPlace == 2)
	{
		return 1;
	}
	return fibonacci(patternPlace - 1) + fibonacci(patternPlace - 2);
}

int main()
{
	int patternPlace;
	cout << "Enter the pattern place: ";
	cin >> patternPlace;
	for (int i = 1; i <= patternPlace; i++)
	{
		cout << fibonacci(i) << " ";
	}
	return 0;
}

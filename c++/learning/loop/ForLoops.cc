#include <iostream>
using namespace std;

void factorial()
{
	int inputNum;
	int factorial = 1;
	cout << "Enter a number: ";
	cin >> inputNum;
	for (int i = inputNum; i >= 1; i--)
	{
		factorial *= i;
	}
	cout << factorial << endl;

	factorial = 1;
	for (int j = 1; j <= inputNum; j++)
	{
		factorial *= j;
	}
	cout << factorial;
}

int main()
{
	factorial();
	return 0;
}

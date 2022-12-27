#include <iostream>
using namespace std;

void numberReverse()
{
	int inputNumber;
	int reverseNumber = 0;
	cout << "Please enter a number: ";
	cin >> inputNumber;
	while (abs(inputNumber) >= 1)
	{
		reverseNumber *= 10;
		reverseNumber = inputNumber % 10 + reverseNumber;
		inputNumber /= 10;
	}
	cout << "The reversed number is: " << reverseNumber;
}

int main()
{
	numberReverse();
	return 0;
}

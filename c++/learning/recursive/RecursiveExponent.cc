#include <iostream>
using namespace std;

double power(double base, double exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	return base * power(base, exponent - 1);
}

int main()
{
	double base, exponent;
	cout << "Enter a base number: ";
	cin >> base;
	cout << "Enter an exponent: ";
	cin >> exponent;
	cout << power(base, exponent);
	return 0;
}

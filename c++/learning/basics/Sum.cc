#include <iostream>
using namespace std;

int sum(int num1, int num2)
{
	return num1 + num2;
}
float sum(float num1, float num2)
{
	return num1 + num2;
}

double sum(double num1, double num2)
{
	return num1 + num2;
}

int main()
{
	int num1, num2;
	cout << sum(num2, num1) << endl;
	cout << sum(2, 2) << endl;
	cout << sum((float)2.1, (float)2.3) << endl;
	cout << sum(2.1, 2.3);

	return 0;
}

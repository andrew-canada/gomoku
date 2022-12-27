#include <iostream>
using namespace std;

void markCalc()
{
	int grade, sum = 0;
	for (int i = 0; i < 3; i++)
	{
		do
		{
			cout << "Enter your " << i + 1 << " grade: ";
			cin >> grade;
		} while (grade < 1 || grade > 5);
		sum += grade;
	}
	cout << "Sum: " << sum << endl;
	cout << "Average: " << (float)sum / 3 << endl;
}

int main()
{
	markCalc();
	return 0;
}

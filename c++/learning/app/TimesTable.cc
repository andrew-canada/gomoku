#include <iostream>
using namespace std;

void timesTable()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << " ";
		}
		cout << endl;
	}
}

int main()
{
	timesTable();
	return 0;
}

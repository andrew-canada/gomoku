#include <iostream>
using namespace std;

void timesTable()
{
	cout << "  ";
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << " ";
	}
	cout << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << i;
		for (int j = 1; j <= 10; j++)
		{
			cout << " " << i * j << " ";
		}
		cout << endl;
	}
}

int main()
{
	timesTable();
	return 0;
}

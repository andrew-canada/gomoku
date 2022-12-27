#include <iostream>
using namespace std;

int main()
{
	int instructionNum = 0;
	int intVal = 0;
	char var1, var2;
	int a = 0, b = 0;
	bool isContinue = true;

	do
	{
		cin >> instructionNum;
		switch (instructionNum)
		{
		case 1:
			cin >> var1 >> intVal;
			if (var1 == 'A')
			{
				a = intVal;
			}
			else
			{
				b = intVal;
			}
			break;
		case 2:
			cin >> var1;
			if (var1 == 'A')
			{
				cout << a << endl;
			}
			else
			{
				cout << b << endl;
			}
			break;
		case 3:
			cin >> var1 >> var2;
			if (var1 == 'A')
				if (var2 == 'A')
				{
					a += a;
				}
				else
				{
					a += b;
				}
			else
			{
				if (var2 == 'A')
				{
					b += a;
				}
				else
				{
					b += b;
				}
			}
			break;
		case 4:
			cin >> var1 >> var2;
			if (var1 == 'A')
				if (var2 == 'A')
				{
					a *= a;
				}
				else
				{
					a *= b;
				}
			else
			{
				if (var2 == 'A')
				{
					b *= a;
				}
				else
				{
					b *= b;
				}
			}
			break;
		case 5:
			cin >> var1 >> var2;
			if (var1 == 'A')
				if (var2 == 'A')
				{
					a -= a;
				}
				else
				{
					a -= b;
				}
			else
			{
				if (var2 == 'A')
				{
					b -= a;
				}
				else
				{
					b -= b;
				}
			}
			break;
		case 6:
			cin >> var1 >> var2;
			if (var1 == 'A')
				if (var2 == 'A')
				{
					a /= a;
				}
				else
				{
					a /= b;
				}
			else
			{
				if (var2 == 'A')
				{
					b /= a;
				}
				else
				{
					b /= b;
				}
			}
			break;
		default:
			isContinue = false;
			break;
		}
	} while (isContinue);
	return 0;
}

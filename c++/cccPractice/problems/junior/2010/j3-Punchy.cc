#include <iostream>
#include <string>
using namespace std;

int main()
{
	int instructionNum;
	char var1, var2;
	int value;
	int a = 0, b = 0;
	bool isContinue = true;
	do
	{
		cin >> instructionNum;
		switch (instructionNum)
		{
		case 1:
			cin >> var1 >> value;
			if (var1 == 'A')
			{
				a = value;
			}
			else
			{
				b = value;
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
			{
				if (var2 == 'B')
				{
					a = a + b;
				}
				else
				{
					a = a + a;
				}
			}
			else
			{
				if (var2 == 'A')
				{
					b = b + a;
				}
				else
				{
					b = b + b;
				}
			}
			break;
		case 4:
			cin >> var1 >> var2;
			if (var1 == 'A')
			{
				if (var2 == 'B')
				{
					a = a * b;
				}
				else
				{
					a = a * a;
				}
			}
			else
			{
				if (var2 == 'A')
				{
					b = b * a;
				}
				else
				{
					b = b * b;
				}
			}
			break;
		case 5:
			cin >> var1 >> var2;
			if (var1 == 'A')
			{
				if (var2 == 'B')
				{
					a = a - b;
				}
				else
				{
					a = a - a;
				}
			}
			else
			{
				if (var2 == 'A')
				{
					b = b - a;
				}
				else
				{
					b = b - b;
				}
			}
			break;
		case 6:
			cin >> var1 >> var2;
			if (var1 == 'A')
			{
				if (var2 == 'B')
				{
					a = a / b;
				}
				else
				{
					a = a / a;
				}
			}
			else
			{
				if (var2 == 'A')
				{
					b = b / a;
				}
				else
				{
					b = b / b;
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

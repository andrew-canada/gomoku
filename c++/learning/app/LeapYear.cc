#include <iostream>
using namespace std;

void leapYear()
{
	//(year%4==0 && year%100!=0 || year%400==0)
	int year, month;
	cout << "Enter a date (y,m): ";
	cin >> year >> month;
	switch (month)
	{
	case 2:
		cout << ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? "29 days" : "28 days") << endl;
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		cout << "31 days" << endl;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "30 days" << endl;
		break;
	default:
		cout << "Invalid input" << endl;
	}
}

int main()
{
	leapYear();
	return 0;
}

#include <iostream>
using namespace std;

void bigOrSmall()
{
	int guestNum, hostNum;
	cout << "Guest, please input your number: ";
	cin >> guestNum;
	system("cls");
	cout << "Host, please input your number: ";
	cin >> hostNum;
	system("cls");
	cout << ((guestNum > hostNum) ? "Guest won" : "Host won") << endl;
}

int main()
{
	bigOrSmall();
	return 0;
}

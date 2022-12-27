#include <iostream>
using namespace std;

int main()
{
	int antennas = 0, eyes = 0;
	cout << "How many antennas?" << endl;
	cin >> antennas;
	cout << "How many eyes?" << endl;
	cin >> eyes;

	if (antennas >= 3 && eyes <= 4)
	{
		cout << "TroyMartian" << endl;
	}
	if (antennas <= 6 && eyes >= 2)
	{
		cout << "VladSaturnian" << endl;
	}
	if (antennas <= 2 && eyes <= 3)
	{
		cout << "GraemeMercurian" << endl;
	}

	return 0;
}

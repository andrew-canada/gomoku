#include <iostream>
using namespace std;

int main()
{
	int youngAge = 0, midAge = 0, oldAge = 0;
	cin >> youngAge >> midAge;
	int ageDiff = midAge - youngAge;
	oldAge = midAge + ageDiff;
	cout << oldAge;
	return 0;
}

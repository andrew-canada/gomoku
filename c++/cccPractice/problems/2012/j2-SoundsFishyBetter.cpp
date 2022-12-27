#include <iostream>
using namespace std;

int main()
{
	int depth1 = 0, depth2 = 0, depth3 = 0, depth4 = 0;
	cin >> depth1 >> depth2 >> depth3 >> depth4;
	if (depth1 < depth2 && depth2 < depth3 && depth3 < depth4)
	{
		cout << "Fish Rising";
	}
	else if (depth1 > depth2 && depth2 > depth3 && depth3 > depth4)
	{
		cout << "Fish Diving";
	}
	else if (depth1 + depth2 + depth3 + depth4 == depth1 * 4)
	{
		cout << "Fish At Constant Depth";
	}
	else
	{
		cout << "No Fish";
	}
	return 0;
}

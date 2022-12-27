#include <iostream>
#include <string>
using namespace std;

static const int npos = -1;

int main()
{
	std::ios_base::sync_with_stdio(false);

	int count = 0;
	string validChars = "IOSHZXN";
	string input;
	cin >> input;

	for (int i = 0; i < (int)input.length(); i++)
	{
		if ((const int)validChars.find(input[i]) != npos)
		{
			count++;
		}
	}
	if (count == (int)input.length())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}

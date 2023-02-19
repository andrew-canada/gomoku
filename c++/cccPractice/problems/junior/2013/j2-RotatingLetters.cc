#include <iostream>
#include <string>
using namespace std;

static const int npos = -1;

int main()
{
	string validChars = "IOSHZXN";
	string input;
	cin >> input;
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		string currentChar = input.substr(i, 1);

		//if (validChars.find(currentChar) == npos) // use line#5 npos
		if (validChars.find(currentChar) == string::npos) // proper way to check
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

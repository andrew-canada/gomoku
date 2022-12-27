#include <iostream>
using namespace std;

void pin()
{
	int pinNumber = 1234;
	int pinAttempt;
	int attemptLimit = 3;
	do
	{
		cout << "Please enter your PIN: ";
		cin >> pinAttempt;
		if (pinAttempt == pinNumber)
		{
			cout << "Welcome";
			break;
		}
		else
		{
			attemptLimit--;
			cout << "Incorrect PIN. " << attemptLimit << " attempts remaining" << endl;
		}

	} while (attemptLimit >= 1);
}

int main()
{
	pin();
	return 0;
}

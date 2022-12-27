#include <iostream>
using namespace std;

void calculator()
{
	float num1, num2;
	char operation;
	cout << "Please enter an expression: ";
	cin >> num1 >> operation >> num2;

	switch (operation)
	{
	case '+':
		cout << num1 << " + " << num2 << " = " << num1 + num2;
		break;
	case '-':
		cout << num1 << " - " << num2 << " = " << num1 - num2;
		break;
	case '*':
		cout << num1 << " * " << num2 << " = " << num1 * num2;
		break;
	case '/':
		cout << num1 << " / " << num2 << " = " << num1 / num2;
		break;
	case '%':
		cout << num1 << " % " << num2 << " = " << int(num1) % int(num2);
		break;
	default:
		cout << "Invalid operation";
	}
}

int main()
{
	calculator();
	return 0;
}

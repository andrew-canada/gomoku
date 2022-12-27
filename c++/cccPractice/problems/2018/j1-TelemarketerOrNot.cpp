#include <iostream>
using namespace std;

int main()
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    cin >> num1 >> num2 >> num3 >> num4;
    if ((num1 == 8 || num1 == 9) && (num4 == 8 || num4 == 9) && (num2 == num3))
    {
        cout << "ignore";
    }
    else
    {
        cout << "answer";
    }
}
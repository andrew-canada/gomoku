#include <iostream>
using namespace std;

int main()
{
    int number = 0;
    cin >> number;
    bool isNegative = (number < 0);
    number = abs(number);
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            if (isNegative)
            {
                cout << -i << " ";
            }
            cout << i << " ";
        }
    }
}
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int inputNum;
    ll factorial;

    cout << "enter number from 0 to 6: " << '\n';

    cin >> inputNum;

    switch (inputNum)
    {
    case 0:
        factorial = 1;
        break;
    case 1:
        factorial = 1;
        break;

    case 2:
        factorial = 2;
        break;

    case 3:
        factorial = 6;
        break;

    case 4:
        factorial = 24;
        break;

    case 5:
        factorial = 120;
        break;

    case 6:
        factorial = 720;
        break;

    default:
        cout << "Invalid input";
        return 1;
    }

    cout << "factorial of " << inputNum << " is: " << factorial;
}
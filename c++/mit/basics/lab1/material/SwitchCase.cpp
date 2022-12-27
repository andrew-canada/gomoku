#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    switch (n)
    {
    case 0:
        cout << "You typed zero .\n";

        // exits (breaks out of) switch statement
        break;

    // falls through - does same thing for 3 cases
    case 1:
    case 4:
    case 9:
        cout << "n is a perfect square .\n";
        break;
    case 2:
        cout << "n is an even number .\n";
    case 3:
    case 5:
    case 7:
        cout << "n is a prime number .\n";
        break;
    case 6:
    case 8:
        cout << "n is an even number .\n";
        break;

    // if nothing else matches - like "else"
    default:
        cout << " Only single - digit positive numbers are allowed .\n";
        break;
    }
}
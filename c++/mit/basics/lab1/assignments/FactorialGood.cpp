#include <iostream >

using namespace std;

typedef long long ll;

int main()
{
    short number;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "number must be a positive integer \n";
        return 1;
    }

    cout << "The factorial of " << number << " is ";
    ll accumulator = 1;
    for (; number > 0; accumulator *= number--)
        ;
    cout << accumulator << ".\n";

    return 0;
}
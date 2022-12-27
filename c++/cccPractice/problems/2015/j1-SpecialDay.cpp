#include <iostream>
using namespace std;

int main()
{
    int month = 0, day = 0;
    cin >> month >> day;
    if (month == 2 && day == 18)
    {
        cout << "Special";
    }
    else if (month < 2 || (month == 2 && day < 18))
    {
        cout << "Before";
    }
    else
    {
        cout << "After";
    }
}
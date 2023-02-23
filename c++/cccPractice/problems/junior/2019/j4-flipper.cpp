#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string input;
    cin >> input;

    if (count(input.begin(), input.end(), 'H') % 2 == 0)
    {
        if (count(input.begin(), input.end(), 'V') % 2 == 0)
        {
            cout << "1 2\n3 4";
        }
        else
        {
            cout << "2 1\n4 3";
        }
    }
    else
    {
        if (count(input.begin(), input.end(), 'V') % 2 == 0)
        {
            cout << "3 4\n1 2";
        }
        else
        {
            cout << "4 3\n2 1";
        }
    }
}
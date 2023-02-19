#include <iostream>

using namespace std;

int main()
{
    int occupied = 0;
    int n;
    cin >> n;
    char *day1 = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> day1[i];
    }
    char *day2 = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> day2[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (day1[i] == 'C' && day2[i] == 'C')
        {
            occupied += 1;
        }
    }
    cout << occupied;
}
#include <iostream>
using namespace std;

int main()
{
    char winOrLose;
    int winCount = 0, loseCount = 0;
    for (int i = 1; i <= 6; i++)
    {
        cin >> winOrLose;
        if (winOrLose == 'W')
        {
            winCount += 1;
        }
        else
        {
            loseCount += 1;
        }
    }
    if (winCount >= 5)
    {
        cout << 1;
    }
    else if (winCount >= 3)
    {
        cout << 2;
    }
    else if (winCount >= 1)
    {
        cout << 3;
    }
    else
    {
        cout << -1;
    }
}
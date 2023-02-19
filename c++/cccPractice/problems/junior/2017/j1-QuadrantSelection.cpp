#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    int xVal = 0, yVal = 0;
    cin >> xVal;
    cin >> yVal;
    if (xVal > 0 && yVal > 0)
    {
        cout << 1;
    }
    else if (xVal < 0 && yVal > 0)
    {
        cout << 2;
    }
    else if (xVal < 0 && yVal < 0)
    {
        cout << 3;
    }
    else
    {
        cout << 4;
    }
}
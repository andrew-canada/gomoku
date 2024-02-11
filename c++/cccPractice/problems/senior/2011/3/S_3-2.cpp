#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e4;

bool crys(int m, int x, int y)
{
    int cx = x / pow(5, m - 1), cy = y / pow(5, m - 1);
    if (cx == 0 || cx == 4)
    {
        return false;
    }
    if (cy == 0 && (cx == 1 || cx == 2 || cx == 3) || cy == 1 && cx == 2)
    {
        return true;
    }
    if (cy == 1 && (cx == 1 || cx == 3) || cy == 2 && cx == 2)
    {
        return crys(m - 1, x % (int)pow(5, m - 1), y % (int)pow(5, m - 1));
    }
    return false;
}

int main()
{
    int t, m, x, y;
    cin >> t;
    while (t--)
    {
        cin >> m >> x >> y;
        cout << (crys(m, x, y) ? "crystal\n" : "empty\n");
    }
}
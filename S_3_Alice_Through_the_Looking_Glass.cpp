// 5x5 grid, scaling each grid into a smaller 5x5 grid
// magnification level m
// bottom left is (0, 0), top right is (5^m-1, 5^m-1)
// check if position (x, y) is filled at magnification m

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

bool crystal(int m, int x, int y);

int main()
{
    int t, m, x, y;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &m, &x, &y);
        crystal(m, x, y) ? printf("crystal\n") : printf("empty\n");
    }
}

bool crystal(int m, int x, int y)
{
    int x1 = x / pow(5, m - 1), y1 = y / pow(5, m - 1);
    if (x1 == 0 || x1 == 4)
    {
        return false;
    }
    else if (x1 > 0 && x1 < 4 && y1 == 0 || x1 == 2 && y1 == 1)
    {
        return true;
    }
    else if ((x1 == 1 || x1 == 3) && y1 == 1 || x1 == 2 && y1 == 2)
    {
        return crystal(m - 1, x % (int)pow(5, m - 1), y % (int)pow(5, m - 1));
    }
    return false;
}
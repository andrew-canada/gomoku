/*
input:
N glass in rectangle shape
Where two pieces of glass overlap,
the tint-factor is the sum of their tint-factors.

output:
area with tint >= T

*/
#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef long long ll;

int n, t;
ll area;
int window[1005][5];
set<int> uniqueX, uniqueY;
int diff[2005][2005];
map<int, int> xPos, yPos;
int xVal[2005], yVal[2005];

int main()
{
    scanf("%d%d", &n, &t);
    REP(i, 0, n)
    {
        scanf("%d%d%d%d%d", &window[i][0], &window[i][1], &window[i][2], &window[i][3], &window[i][4]);
        uniqueX.insert(window[i][0]);
        uniqueX.insert(window[i][2]);
        uniqueY.insert(window[i][1]);
        uniqueY.insert(window[i][3]);
    }
    int i = 0;
    for (int x : uniqueX)
    {
        xPos[x] = ++i;
        xVal[i] = x;
    }
    i = 0;
    for (int y : uniqueY)
    {
        yPos[y] = ++i;
        yVal[i] = y;
    }
    for (const auto &w : window)
    {
        diff[xPos[w[0]]][yPos[w[1]]] += w[4];
        diff[xPos[w[2]]][yPos[w[3]]] += w[4];
        diff[xPos[w[0]]][yPos[w[3]]] -= w[4];
        diff[xPos[w[2]]][yPos[w[1]]] -= w[4];
    }
    int dx, dy;
    REP(i, 1, uniqueX.size())
    {
        REP(j, 1, uniqueY.size())
        {
            diff[i][j] = diff[i][j] + diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
            if (diff[i][j] >= t)
            {
                dx = xVal[i + 1] - xVal[i];
                dy = yVal[j + 1] - yVal[j];
                area += (ll)dx * dy;
            }
        }
    }
    printf("%lld", area);
};
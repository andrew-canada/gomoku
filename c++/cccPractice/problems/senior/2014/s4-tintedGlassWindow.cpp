#include <stdio.h>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n, t;
int wa[1005][5];
int diff[2005][2005];
int xVal[2005], yVal[2005];
set<int> distX, distY;
map<int, int> xPos, yPos;
ll area;

int main()
{
    // freopen("s4.in", "r", stdin);
    // freopen("s4.out", "w", stdout);
    scanf("%d%d", &n, &t);
    REP(i, 0, n - 1)
    {
        scanf("%d%d%d%d%d", &wa[i][0], &wa[i][1], &wa[i][2], &wa[i][3], &wa[i][4]);
        distX.emplace(wa[i][0]);
        distX.emplace(wa[i][2]);
        distY.emplace(wa[i][1]);
        distY.emplace(wa[i][3]);
    }
    int pos = 0;
    for (int x : distX)
    {
        xPos[x] = ++pos;
        xVal[pos] = x;
    }
    pos = 0;
    for (int y : distY)
    {
        yPos[y] = ++pos;
        yVal[pos] = y;
    }
    for (const auto &w : wa)
    {
        diff[xPos[w[0]]][yPos[w[1]]] += w[4];
        diff[xPos[w[2]]][yPos[w[3]]] += w[4];
        diff[xPos[w[0]]][yPos[w[3]]] -= w[4];
        diff[xPos[w[2]]][yPos[w[1]]] -= w[4];
    }
    ll dy, dx;
    REP(i, 1, distX.size() - 1)
    {
        REP(j, 1, distY.size() - 1)
        {
            diff[i][j] = diff[i][j] + diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
            if (diff[i][j] >= t)
            {
                dy = yVal[j + 1] - yVal[j];
                dx = xVal[i + 1] - xVal[i];
                area += dy * dx;
            }
        }
    }
    printf("%lld", area);
}
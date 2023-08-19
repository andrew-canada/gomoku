#include <stdio.h>
#include <map>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

int n, t;
int tx[2005], ty[2005], bx[2005], by[2005], tint[2005];
int diff[2005][2005];
ll area;
map<int, int> xCoord, yCoord;

int main()
{
    scanf("%d%d", &n, &t);
    int tlx, tly, brx, bry, ti;
    REP(i, 1, n)
    {
        scanf("%d%d%d%d%d", tx[i], ty[i], bx[i], by[i], tint[i]);
        xCoord[tx[i]] = xCoord[bx[i]] = yCoord[ty[i]] = yCoord[by[i]] = 0;
    }
    int val = 1;
    for (auto &xc : xCoord)
    {
        xc.second = val++;
    }
    val = 1;
    for (auto &yc : yCoord)
    {
        yc.second = val++;
    }
    REP(i, 1, n)
    {
    }
    REP(i, 1, xCoord.size())
    {
        REP(j, 1, yCoord.size())
        {
        }
    }
    printf("%lld", area);
}
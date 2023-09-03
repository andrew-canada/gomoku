#include <stdio.h>
#include <numeric>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 150005

int n, m;
int req[INF][3];
int st[2 * INF];
int gcdLcm[INF];
int diff[INF][17];
int netChange[17];

int query(int s, int e);

int main()
{
    // freopen("s5.in", "r", stdin);
    scanf("%d%d", &n, &m);
    fill(gcdLcm, gcdLcm + n + 1, 1);
    REP(i, 0, m - 1)
    {
        scanf("%d%d%d", &req[i][0], &req[i][1], &req[i][2]);
        diff[req[i][0]][req[i][2]]++;
        diff[req[i][1] + 1][req[i][2]]--;
    }
    REP(i, 1, n)
    {
        REP(j, 1, 16)
        {
            netChange[j] += diff[i][j];
        }
        REP(j, 1, 16)
        {
            if (netChange[j])
            {
                gcdLcm[i] = lcm(gcdLcm[i], j);
            }
        }
        st[i + n - 1] = gcdLcm[i];
    }

    for (int i = n - 1; i >= 1; i--)
    {
        st[i] = gcd(st[2 * i], st[2 * i + 1]);
    }
    REP(i, 0, m - 1)
    {
        const auto &[s, e, gcdVal] = req[i];
        // printf("in\n");
        if (query(s, e) != gcdVal)
        {
            printf("Impossible");
            return 0;
        }
    }
    REP(i, 1, n)
    {
        printf("%d ", gcdLcm[i]);
    }
}

int query(int s, int e)
{
    s += n - 1, e += n;
    // printf("1||%d %d\n", s, e);
    int gcdVal = 0;
    while (s < e)
    {
        if (s & 1)
        {
            gcdVal = gcd(gcdVal, st[s++]);
        }
        if (e & 1)
        {
            gcdVal = gcd(gcdVal, st[--e]);
        }
        // printf("gcd func: %d\n", gcdVal);
        // printf("2||%d %d\n", s, e);
        e >>= 1, s >>= 1;
        // printf("3||%d %d\n", s, e);
    }
    return gcdVal;
}
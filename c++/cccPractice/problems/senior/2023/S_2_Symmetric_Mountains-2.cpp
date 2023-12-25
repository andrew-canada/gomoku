/*
n column; column i has height h(i)
define crop as contiguous columns from l to r
define diff as sum of difference between h(l) and h(r), moving out from center of crop
output n number, n(i) is min difference of crop of length n (start from 1)
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

int h[100005];
int md[100005];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &h[i]);
    }
    memset(md, INF, sizeof(md));
    int mv;
    REP(i, 0, n)
    {
        mv = 0;
        for (int len = 0; i + len < n && i - len >= 0; len++)
        {
            mv += abs(h[i + len] - h[i - len]);
            md[2 * len + 1] = min(md[2 * len + 1], mv);
        }
        mv = 0;
        for (int len = 0; i + len + 1 < n && i - len >= 0; len++)
        {
            mv += abs(h[i + len + 1] - h[i - len]);
            md[2 * (len + 1)] = min(md[2 * (len + 1)], mv);
        }
    }
    REP(i, 1, n + 1)
    {
        printf("%d ", md[i]);
    }
}
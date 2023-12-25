/*
circle centered at origin with circumference c>=3
n points on circle at integer locations (can have multiple at one point)
points begin at rightmost, then go counterclockwise
define good triplet: origin is INSIDE triangle at vertices a, b, c
define different triplet: one of the three points is different
find number of distinct good triplets
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef long long ll;
ll pts[1000005];
ll psa[1000005];
ll gt;

int main()
{
    ll n, c;
    scanf("%lld%lld", &n, &c);
    ll pt;
    REP(i, 0, n)
    {
        scanf("%lld", &pt);
        pts[pt]++;
    }
    psa[0] = pts[0];
    REP(i, 1, c)
    {
        psa[i] = psa[i - 1] + pts[i];
    }
    gt = n * (n - 1) * (n - 2) / 6;
    ll opp;
    ll np;
    REP(i, 0, c)
    {
        opp = (i + (c / 2)) % c;
        if (i < opp)
        {
            np = psa[opp] - psa[i - 1];
        }
        else
        {
            np = psa[opp] + psa[c - 1] - psa[i - 1];
        }
        // printf("before %lld\n", gt);
        gt = gt - pts[i] * (np - pts[i]) * (np - pts[i] - 1) / 2 - pts[i] * (pts[i] - 1) * (np - pts[i]) / 2 - pts[i] * (pts[i] - 1) * (pts[i] - 2) / 6;
        // printf("after %lld\n", gt);
    }

    if (c % 2 == 0)
    {
        REP(i, 0, c / 2)
        {
            opp = (i + (c / 2)) % c;
            // gt = gt + pts[i] * (pts[opp] - 1) * (pts[opp] - 2) / 2 + pts[i] * (pts[i] - 1) * (pts[opp] - 2) / 2;
            gt = gt + pts[i] * (pts[opp]) * (pts[opp] - 1) / 2 + pts[i] * (pts[i] - 1) * (pts[opp]) / 2;
        }
    }
    printf("%lld", gt);
}
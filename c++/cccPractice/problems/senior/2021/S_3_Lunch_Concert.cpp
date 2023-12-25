/*
n friend arranged in number line
attribute of frind:
1. p, position
2. w, seconds to walk one meter
3. d, hearing range

pick position c to minimize total walking time to hear

using longlong
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

ll p[200005], w[200005], d[200005];

ll totTime(ll pos, ll n);

int main()
{
    ll n;
    scanf("%lld", &n);
    REP(i, 0, n)
    {
        scanf("%lld%lld%lld", &p[i], &w[i], &d[i]);
    }
    ll low = 0, high = 1e9;
    ll mid;
    ll tt1, tt2;
    while (low < high)
    {
        mid = (low + high) / 2;
        tt1 = totTime(mid, n);
        tt2 = totTime(mid + 1, n);
        if (tt1 <= tt2)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%lld", totTime(low, n));
}

ll totTime(ll pos, ll n)
{
    ll tt = 0;
    REP(i, 0, n)
    {
        if (p[i] < pos - d[i])
        {
            tt += w[i] * (pos - d[i] - p[i]);
        }
        else if (p[i] > pos + d[i])
        {
            tt += w[i] * (p[i] - d[i] - pos);
        }
    }
    return tt;
}
#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef long long ll;

int n, c;
int pos;
ll pts[1000005];
int psa[1000005];
ll nt;

int main()
{
    scanf("%d%d", &n, &c);
    REP(i, 0, n)
    {
        scanf("%d", &pos);
        pts[pos]++;
    }
    psa[0] = pts[0];
    REP(i, 1, c)
    {
        psa[i] = psa[i - 1] + pts[i];
    }
    ll ln = n;
    nt = ln * (ln - 1) * (ln - 2) / 6;
    ll lc = c;
    for (ll i = 0; i < lc; i++)
    {
        ll opp = (i + lc / 2) % lc;
        ll num = 0;
        if (i < opp)
        {
            num = psa[opp] - (i + 1 == 0 ? 0 : psa[i]);
        }
        else
        {
            num = psa[opp] + psa[c - 1] - psa[i];
        }
        nt = nt - (pts[i] * num * (num - 1) / 2) - (num * pts[i] * (pts[i] - 1) / 2) - (pts[i] * (pts[i] - 1) * (pts[i] - 2) / 6);
    }
    if (c % 2 == 0)
    {
        for (ll i = 0; i < lc / 2; i++)
        {
            ll opp = i + lc / 2;
            nt = nt + (pts[opp] * pts[i] * (pts[i] - 1) / 2) + (pts[i] * pts[opp] * (pts[opp] - 1) / 2);
        }
    }
    printf("%lld", nt);
}
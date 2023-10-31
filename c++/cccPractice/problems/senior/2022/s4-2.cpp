#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

int n, c;
int pts[1000005];
int psa[1000005];
ll nt;

int main()
{
    scanf("%d%d", &n, &c);
    int pt;
    REP(i, 0, n - 1)
    {
        scanf("%d", &pt);
        pts[pt]++;
    }
    psa[0] = pts[0];
    REP(i, 1, c)
    {
        psa[i] = psa[i - 1] + pts[i];
    }
    nt = (ll)n * (n - 1) * (n - 2) / 6;
    REP(i, 0, c)
    {
        int opp = (i + c / 2) % c;
        ll num = 0;
        if (i < opp)
        {
            num = psa[opp] - (i + 1 == 0 ? 0 : psa[i]);
        }
        else
        {
            num = psa[c - 1] + psa[opp] - psa[i];
        }
        nt = nt - (ll)pts[i] * num * (num - 1) / 2 - (ll)num * pts[i] * (pts[i] - 1) / 2 - (ll)pts[i] * (pts[i] - 1) * (pts[i] - 2) / 6;
    }
    if (c % 2 == 0)
    {
        REP(i, 0, c / 2)
        {
            int opp = i + c / 2;
            nt = nt + (ll)pts[opp] * pts[i] * (pts[i] - 1) / 2 + (ll)pts[i] * pts[opp] * (pts[opp] - 1) / 2;
        }
    }
    printf("%lld", nt);
}
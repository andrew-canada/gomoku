#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;

ll n, m, k;
ll rs;
int p[1000005];

int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    rs = k - n;
    if (rs < 0)
    {
        printf("-1");
        return 0;
    }
    int i = 0;
    while (i < m)
    {
        if (rs < i)
        {
            break;
        }
        p[i] = i + 1;
        rs -= i;
        i++;
    }
    int nxt = 0;
    while (i < n)
    {
        nxt = MIN(m - 1, rs);
        p[i] = p[i - nxt - 1];
        rs -= nxt;
        i++;
    }
    if (rs == 0)
    {
        REP(i, 0, n)
        {
            printf("%d ", p[i]);
        }
    }
    else
    {
        printf("-1");
    }
}
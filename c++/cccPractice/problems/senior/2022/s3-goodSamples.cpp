#include <stdio.h>

// #define LOCAL
#define min(a, b) (a < b ? a : b)

typedef long long ll;

ll n, m, k;
int p[1000005];

int main()
{
#ifdef LOCAL
    freopen("s3.in", "r", stdin);
    freopen("s3.out", "w", stdout);
#endif
    scanf("%lld %lld %lld", &n, &m, &k);
    ll r = k - n;
    if (r < 0)
    {
        puts("-1");
        return 0;
    }
    int i = 0;
    while (i < m)
    {
        if (r < i)
        {
            break;
        }
        p[i] = i + 1;
        r -= i;
        i++;
    }
    int next = 0;
    while (i < n)
    {
        next = min(r, m - 1);
        p[i] = p[i - 1 - next];
        r -= next;
        i++;
    }
    if (r == 0)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", p[j]);
        }
    }
    else
    {
        puts("-1");
    }
}
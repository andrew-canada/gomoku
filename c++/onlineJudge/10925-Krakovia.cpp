#include <stdio.h>

// #define LOCAL

typedef long long ll;

int i = 1;
int ni, np;
__int128 tot;
__int128 val;

int main()
{
#ifdef LOCAL
    freopen("10925.in", "r", stdin);
    freopen("10925.out", "w", stdout);
#endif
    while (scanf("%d %d", &ni, &np), ni && np)
    {
        while (ni--)
        {
            scanf("%lld", &val);
            tot += val;
        }
        printf("Bill #%d costs %lld: each friend should pay %lld\n\n", i, static_cast<ll>(tot), static_cast<ll>(tot / np));
        i++;
        tot = 0;
    }
}
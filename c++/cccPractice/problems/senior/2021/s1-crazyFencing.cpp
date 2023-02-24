#include <stdio.h>

// #define LOCAL

int n;
int sides[10001];
int h, b;
double tot;

int main()
{
#ifdef LOCAL
    freopen("s1.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%d", &sides[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b);
        tot += b * ((double)sides[i] + sides[i + 1]) / 2;
    }
    printf("%.1f", tot);
}
#include <stdio.h>
#include <algorithm>

// #define LOCAL

typedef long long ll;

int n;
ll heights[5005];
ll values[5005][5005];

int main()
{
#ifdef LOCAL
    freopen("s2.in", "r", stdin);
    freopen("s2.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &heights[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int l = 1;
        int r = i;
        ll minDiff = 1e9;
        while (r <= n)
        {
            values[l][r] = abs(heights[r] - heights[l]) + values[l + 1][r - 1];
            minDiff = std::min(values[l][r], minDiff);
            l++;
            r++;
        }
        printf("%d ", minDiff);
    }
    printf("\n");
}
#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int h[10005];

int main()
{
    int n;
    int w;
    double ans;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &h[i]);
    }
    REP(i, 0, n - 1)
    {
        scanf("%d", &w);
        ans += (1.0 * h[i] + h[i + 1]) * w;
    }
    printf("%.1lf", ans / 2);
}
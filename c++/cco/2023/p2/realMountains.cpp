// n columns of pixels of height Hn
// peak is higher than left and right
// result only has one peak
// (i, j, k) -> peak j increments for cost Hi+Hj+Hk
// minimize cost to create single peak

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int MAXN = 1000005;
int cost;
int h[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &h[i]);
    }
    int ch;
    int peaks = 1;
    while (peaks > 0)
    {
        peaks = 0;
        REP(i, 1, n)
        {
            if (i - 1 >= 1 && i + 1 <= n && h[i] > h[i - 1] && h[i] > h[i + 1])
            {
                peaks++;
            }
            else if (i + 1 <= n && h[i] > h[i + 1])
            {
                peaks++;
                h[i + 1] = h[i];
            }
            else if (i - 1 >= 1 && h[i] > h[i - 1])
            {
                peaks++;
                h[i - 1] = h[i];
            }
            // ch = max(h[i - 1], h[i + 1]);
            // if (ch > h[i])
            // {
            //     peaks++;
            //     h[i - 1] = h[i] = h[i + 1] = ch;
            // }
        }
    }
    printf("%d", cost);
}
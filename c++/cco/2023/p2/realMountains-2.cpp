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
int dp[MAXN];
vector<int> p;
bool isP[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &h[i]);
    }

    REP(i, 2, n)
    int ch;
    int peaks;
    while (1)
    {
        peaks = 0;
        if (h[1] > h[2])
        {
            isP[1] = 1;
            peaks++;
        }
        if (h[n] > h[n - 1])
        {
            isP[n] = 1;
            peaks++;
        }
        REP(i, 1, n)
        {
            if (i - 1 >= 1 && i + 1 <= n && h[i] > h[i - 1] && h[i] > h[i + 1])
            {
                isP[i] = 1;
                peaks++;
            }
        }
        if (peaks == 0 || peaks == 1)
        {
            break;
        }
        REP(i, 1, n)
        {
            // find values between peaks
        }
    }
    printf("%d", cost);
}
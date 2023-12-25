// n columns of pixels of height Hn
// peak is higher than left and right
// result only has one peak
// (i, j, k) -> peak j increments for cost Hi+Hj+Hk
// minimize cost to create single peak

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f
#define pb push_back

const int MAXN = 1000005;
int cost;
int h[MAXN];
int dp[MAXN];
vector<int> p;
// bool isP[MAXN];
vector<int> minH;

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &h[i]);
        minH.pb(h[i]);
    }

    REP(i, 2, n)
    int ch;
    int peaks;
    while (1)
    {
        peaks = 0;
        p.clear();
        if (h[1] > h[2])
        {
            // isP[1] = 1;
            p.pb(1);
            peaks++;
        }
        if (h[n] > h[n - 1])
        {
            // isP[n] = 1;
            p.pb(n);
            peaks++;
        }
        REP(i, 1, n)
        {
            if (i - 1 >= 1 && i + 1 <= n && h[i] > h[i - 1] && h[i] > h[i + 1])
            {
                // isP[i] = 1;
                p.pb(i);
                peaks++;
            }
        }
        if (peaks < 2)
        {
            break;
        }
        int mh;
        sort(minH.begin(), minH.end());
        REP(i, 0, p.size() - 1)
        {
            mh = min(p[i], p[i + 1]);
            REP(j, p[i] + 1, p[i + 1] - 1)
            {
                if (p[i] == minH.back() || p[i + 1] == minH.back())
                {
                    continue;
                }
                while (h[j] < mh)
                {
                    cost += minH[0] + minH[1] + h[j];
                    minH[distance(minH.begin(), find(minH.begin(), minH.end(), h[j]))]++;
                    h[j]++;
                    sort(minH.begin(), minH.end());
                }
            }
        }
    }
    printf("%d", cost);
}
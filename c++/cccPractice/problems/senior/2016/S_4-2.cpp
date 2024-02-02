#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 400;

int arr[mxN + 1];
ll psa[mxN + 1], dp[mxN + 1][mxN + 1];

int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        psa[i] = psa[i - 1] + arr[i];
        dp[i][i] = arr[i];
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    int r, cl, cr;
    // loop all range sizes
    for (int i = 1; i < n; i++)
    {
        // left of range
        for (int l = 1; l <= n - i; l++)
        {
            r = l + i;
            cl = l, cr = r;
            // attempt to merge riceballs in range. check for max
            while (cl < cr)
            {
                if (dp[l][cl] && (dp[l][cl] == dp[cr][r]) && (cr == cl + 1 || dp[cl + 1][cr - 1]))
                {
                    dp[l][r] = max(dp[l][r], dp[l][cl] + dp[cl + 1][cr - 1] + dp[cr][r]);
                    ans = max(ans, dp[l][r]);
                    break;
                }
                if (psa[cl] - psa[l - 1] > psa[r] - psa[cr - 1])
                {
                    cr--;
                }
                else
                {
                    cl++;
                }
            }
        }
    }
    cout << ans;
}
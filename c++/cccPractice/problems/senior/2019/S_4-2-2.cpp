#include <bits/stdc++.h>

using namespace std;

#define INF 0xf3f3f3f

typedef long long ll;

const int mxN = 1e6;

int n, k;
int arr[mxN + 1], day[mxN + 1], pref[mxN + 1];
ll dp[mxN + 1], rev[mxN + 1], mxDay[mxN + 1];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        day[i] = (k + i - 1) / k;
    }
    for (int i = 1; i <= k; i++)
    {
        pref[i] = dp[i] = max(pref[i - 1], arr[i]);
    }
    for (int i = k + 1; i <= n; i += k)
    {
        int suf = 0;
        for (int j = k * (day[i] - 1); j >= k * (day[i] - 2); j--)
        {
            rev[j] = max(rev[j + 1], dp[j]);
            mxDay[j] = max(mxDay[j + 1], dp[j] + suf);
            suf = max(arr[j], suf);
        }
        for (int j = i; j <= min(n, i + k); j++)
        {
            if (day[j] == day[j - 1])
            {
                pref[j] = max(pref[j - 1], arr[j]);
            }
            else
            {
                pref[j] = arr[j];
            }
            dp[j] = max(mxDay[j - k], pref[j] + rev[j - k]);
        }
    }
    cout << dp[n];
}
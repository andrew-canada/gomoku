#include <bits/stdc++.h>

using namespace std;

#define INF 0xf3f3f3f

typedef long long ll;

const int mxN = 1e6;

int n, k;
int arr[mxN + 1];
ll dp[mxN + 1];

struct node
{
    int mx;
} st[4 * mxN + 1];

void update(int l, int val, int ti = 1, int tl = 1, int tr = n)
{
    if (tl == tr)
    {
        st[ti].mx = val;
        return;
    }
    int mid = (tl + tr) / 2;
    if (l <= mid)
    {
        update(l, val, ti << 1, tl, mid);
    }
    else
    {
        update(l, val, (ti << 1) + 1, mid + 1, tr);
    }
    st[ti].mx = max(st[ti << 1].mx, st[(ti << 1) + 1].mx);
}

int query(int l, int r, int ti = 1, int tl = 1, int tr = n)
{
    if (tl >= l && tr <= r)
    {
        return st[ti].mx;
    }
    if (l > r)
    {
        return 0;
    }
    int mid = (tl + tr) / 2;
    return max(l <= mid ? query(l, r, ti << 1, tl, mid) : 0,
               r > mid ? query(l, r, (ti << 1) + 1, mid + 1, tr) : 0);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
    int nd = ceil(1.0 * n / k);
    int lastDayAtr = nd * k - n;
    dp[n] = 0;
    for (int d = 1; d <= nd; d++)
    {
        int first = n - d * k, last = min(first + k, n);
        int r = min(last + lastDayAtr, n);
        for (int l = first + lastDayAtr; l >= max(0, first); l--)
        {
            r = min(l + k, r);
            dp[l] = dp[r] + query(l + 1, r);
            ll maxScore;
            while ((maxScore = dp[r - 1] + query(l + 1, r - 1)) >= dp[l] && r > last)
            {
                dp[l] = maxScore;
                r--;
            }
        }
    }
    cout << dp[0];
}
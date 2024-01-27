#include <bits/stdc++.h>

using namespace std;

#define INF 0xf3f3f3f

typedef long long ll;

const int mxN = 3e3;

int arr[mxN + 1][mxN + 1];

void update(int n, int k)
{
    if (k == 1)
    {
        return;
    }
    int nxt;
    if (k == 2)
    {
        nxt = 1;
    }
    else
    {
        nxt = ceil(k * 2.0 / 3);
    }
    update(n, nxt);
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            arr[i][j] = max({arr[i][j], arr[i + k - nxt][j], arr[i + k - nxt][j + k - nxt]});
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    update(n, k);
    ll ans = 0;
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            ans += arr[i][j];
        }
    }
    cout << ans;
}
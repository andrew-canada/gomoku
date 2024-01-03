#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3, mxX = 1e5;

int price[mxN + 1], page[mxN + 1], dp[mxX + 1];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> page[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
    }
    cout << dp[x];
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3, mxX = 1e5;

int dp[mxN + 1][mxX + 1];
int price[mxN + 1];
int page[mxN + 1];

int main()
{
    // freopen("1158.in", "r", stdin);
    int numB, totP;
    cin >> numB >> totP;
    for (int i = 1; i <= numB; i++)
    {
        cin >> price[i];
    }
    for (int i = 1; i <= numB; i++)
    {
        cin >> page[i];
    }
    for (int i = 1; i <= numB; i++)
    {
        for (int j = 1; j <= totP; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + page[i]);
            }
        }
    }
    cout << dp[numB][totP];
}
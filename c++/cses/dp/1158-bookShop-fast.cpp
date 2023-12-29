#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3, mxX = 1e5;

int dp[mxX + 1];
int price[mxN + 1];
int page[mxN + 1];

int main()
{
    // freopen("1158.in", "r", stdin);
    int numB, totPr;
    cin >> numB >> totPr;
    for (int i = 0; i < numB; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < numB; i++)
    {
        cin >> page[i];
    }
    for (int i = 0; i < numB; i++)
    {
        for (int j = totPr; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
    }
    cout << dp[totPr];
}
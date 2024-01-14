#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(1e4 + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int c : coins)
        {
            if (i >= c)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[amount] == 1e9 ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << '\n';
}
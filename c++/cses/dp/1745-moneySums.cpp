#include <bits/stdc++.h>

using namespace std;

const int mxN = 100, mxX = 1e5;

int coin[mxN + 1];
int dp[mxX + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int sum = mxX; sum >= coin[i]; sum--)
        {
            dp[sum] |= dp[sum - coin[i]];
        }
    }
    vector<int> ans;
    for (int i = 1; i <= mxX; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
    {
        cout << i << " ";
    }
}
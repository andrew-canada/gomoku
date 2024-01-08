#include <bits/stdc++.h>

using namespace std;

const int mxN = 100, mxX = 1e5;

int c[mxN + 1];
bool dp[mxX + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    dp[0] = 1;
    for (int i : c)
    {
        for (int s = mxX; s >= i; s--)
        {
            dp[s] |= dp[s - i];
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
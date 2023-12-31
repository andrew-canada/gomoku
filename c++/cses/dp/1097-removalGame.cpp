#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxX = 5e3;
int arr[mxX + 1];
array<ll, 2> dp[mxX + 1][mxX + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // same as loop [n-1, -1)
    for (int i = n - 1; ~i; i--)
    {
        for (int j = i; j < n; j++)
        {
            array<ll, 2> cur;
            if (i == j)
            {
                cur = {arr[i], 0};
            }
            else
            {
                if (dp[i + 1][j][1] + arr[i] > dp[i][j - 1][1] + arr[j])
                {
                    cur = {dp[i + 1][j][1] + arr[i], dp[i + 1][j][0]};
                }
                else
                {
                    cur = {dp[i][j - 1][1] + arr[j], dp[i][j - 1][0]};
                }
            }
            dp[i][j] = cur;
        }
    }
    cout << dp[0][n - 1][0];
}
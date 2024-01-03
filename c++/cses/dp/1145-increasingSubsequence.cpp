#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 * 2;

int arr[mxN + 1];
int dp[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(arr, arr + n, arr[i]);
        if (it != arr + n)
        {
            dp[arr[i]]++;
            len = max(len, dp[arr[i]]);
        }
    }
    cout << len;
}
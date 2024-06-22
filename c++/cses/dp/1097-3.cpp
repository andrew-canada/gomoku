#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e3;

int arr[mxN + 1];
array<ll, 2> dp[mxN + 1][mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << dp[0][n - 1][0];
}
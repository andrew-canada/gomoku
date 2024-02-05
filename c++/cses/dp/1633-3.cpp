#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 1e6;
const ll INF = 5e13, NINF = -5e13, M = 1e9 + 7;

ll dp[mxN + 1];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i >= j)
            {
                dp[i] = (dp[i] + dp[i - j]) % M;
            }
        }
    }
    cout << dp[n];
}
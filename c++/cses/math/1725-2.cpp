#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 100, mxX = 1e6, M = 1e9 + 7, mxS = 600;

double dp[mxN + 1][mxS + 1];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                dp[i + 1][j + k] += dp[i][j] / 6;
            }
        }
    }
    double ans = 0;
    for (int i = a; i <= b; i++)
    {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans;
}
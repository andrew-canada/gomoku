#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6;

int fav[mxN + 1];
double dp[mxN + 1];
map<int, int> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fav[i];
    }
    if (fav[0] == fav[n - 1])
    {
        cout << 1;
        return 0;
    }
    // dp[i] = prob coach steals person i's burger
    double ans = 0;
    // last person of a burger type
    mp[fav[n]] = n;
    for (int i = 2; i <= n; i++)
    {
        if (fav[i] == fav[n])
        {
        }
    }
    cout << ans;
}
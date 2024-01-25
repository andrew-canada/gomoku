#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int M = 1e9 + 7, mxN = 2e5, mxX = 1e6;

int freq[mxX + 1];

int main()
{
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll r = n / (n / i);
        ans += n / i * (r * (r + 1) / 2 - i * (i - 1) / 2);
        i = r;
    }
    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int M = 1e9 + 7, mxX = 1e6;

ll nc2(ll n)
{
    return (((n % M) * ((n - 1) % M)) % M * ((M + 1) / 2)) % M;
}

int main()
{
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll nxt = n / (n / i);
        ans += (n / i % M) * (nc2(nxt + 1) - nc2(i)) % M;
        i = nxt;
    }
    cout << ans % M;
}
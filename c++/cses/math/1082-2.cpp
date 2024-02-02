#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxX = 1e6, M = 1e9 + 7;

ll nC2(ll n)
{
    // n*(n-1)/2
    // mod inverse
    return (((n % M) * ((n - 1) % M)) % M * ((M + 1) / 2)) % M;
}

int main()
{
    ll n, ans = 0, nxt;
    cin >> n;
    // i is a divisor. it occurs n/i times
    for (ll i = 1; i <= n; i++)
    {
        // next divisor that would occur a different number of times
        nxt = n / (n / i);
        ans += ((n / i % M) * (nC2(nxt + 1) - nC2(i)) % M) % M;
        i = nxt;
    }
    cout << ans % M;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ul;
#define eb emplace_back
const ll mod = 1e9 + 7;
const ll MAXN = 1e9 + 29;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(nullptr);
    ll tt;
    cin >> tt;
    while (tt--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> v(n + 3, 0), pref(n + 3, 0);
        while (q--)
        {
            ll a, d, l, r;
            cin >> a >> d >> l >> r;
            v[l - 1] += (-a);
            v[r] += (a + (d * (r - l)));

            pref[l - 1] += d;
            pref[r - 1] += (-d);
        }

        for (ll i = n; i >= 1; i--)
        {
            pref[i] += pref[i + 1];
            v[i] += v[i + 1] + pref[i];
        }
        for (ll i = 1; i <= n; i++)
            cout << v[i] % mod << " ";
        cout << "\n";
    }
}
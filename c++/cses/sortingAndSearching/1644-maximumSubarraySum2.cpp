#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll psa[mxN + 1];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    ll ans = -2e14;
    set<array<ll, 2>> s;
    for (int i = 0; i <= n; i++)
    {
        if (i >= a)
        {
            s.insert({psa[i - a], i - a});
        }
        if (s.size())
        {
            ans = max(ans, psa[i] - (*s.begin())[0]);
        }
        if (i >= b)
        {
            s.erase({psa[i - b], i - b});
        }
    }
    cout << ans;
}
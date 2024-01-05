#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, r, c;
    cin >> n;
    while (n--)
    {
        cin >> r >> c;
        ll maxSL = max(r, c);
        ll prevMax = (maxSL - 1) * (maxSL - 1);
        ll ans;
        if (maxSL & 1)
        {
            if (r == maxSL)
            {
                ans = prevMax + c;
            }
            else
            {
                ans = prevMax + 2 * maxSL - r;
            }
        }
        else
        {
            if (r == maxSL)
            {
                ans = prevMax + 2 * maxSL - c;
            }
            else
            {
                ans = prevMax + r;
            }
        }
        cout << ans << '\n';
    }
}
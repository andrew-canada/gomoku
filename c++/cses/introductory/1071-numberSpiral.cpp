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
        if (maxSL % 2 == 0)
        {
            if (r == maxSL)
            {
            }
            else
            {
            }
        }
        else
        {
            if (r == maxSL)
            {
            }
            else
            {
            }
        }
        cout << ans << '\n';
    }
}
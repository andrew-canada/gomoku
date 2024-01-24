#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int M = 1e9 + 7;

ll exp(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % M;
        }
        a = a * a % M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        cout << exp(a, b) << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, M = 1e9 + 7;

ll exp(ll a, ll pow, int m)
{
    ll b = a;
    a = 1;
    while (pow)
    {
        if (pow & 1)
        {
            a = (a * b) % m;
        }
        b = (b * b) % m;
        pow >>= 1;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    ll a, b, c, n1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        n1 = exp(b, c, M - 1);
        cout << exp(a, n1, M) << '\n';
    }
}
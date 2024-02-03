#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxA = 1e6, M = 1e9 + 7;

ll inv[mxA + 1], f[mxA + 1], invF[mxA + 1];

int main()
{
    ll n, a, b;
    cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= mxA; i++)
    {
        inv[i] = M - M / i * inv[M % i] % M;
    }
    f[0] = invF[0] = 1;
    for (int i = 1; i <= mxA; i++)
    {
        f[i] = f[i - 1] * i % M;
        invF[i] = invF[i - 1] * inv[i] % M;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << f[a] * invF[b] % M * invF[a - b] % M << '\n';
    }
}
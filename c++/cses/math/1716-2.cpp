#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxA = 1e6, M = 1e9 + 7;

ll inv[2 * mxA + 1], f[2 * mxA + 1], invF[2 * mxA + 1];

int main()
{
    ll n, m;
    cin >> n >> m;
    inv[1] = 1;
    for (int i = 2; i <= 2 * mxA; i++)
    {
        inv[i] = M - M / i * inv[M % i] % M;
    }
    f[0] = invF[0] = 1;
    for (int i = 1; i <= 2 * mxA; i++)
    {
        f[i] = f[i - 1] * i % M;
        invF[i] = invF[i - 1] * inv[i] % M;
    }
    cout << ((f[n - 1 + m] * invF[n - 1]) % M * invF[m]) % M;
}
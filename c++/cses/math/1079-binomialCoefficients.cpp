#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;

const int M = 1e9 + 7, mxA = 1e6;

ull fact[mxA + 1], inv[mxA + 1];

ull aCb(ull a, ull b)
{
    return fact[a] * inv[b] % M * inv[a - b] % M;
}

ull exp(ull b, ull e)
{
    ull ans = 1;
    b %= M;
    while (e >= 1)
    {
        if (e & 1)
        {
            ans = (ans * b) % M;
        }
        e >>= 1;
        b = (b * b) % M;
    }
    return ans % M;
}

void precomp()
{
    fact[0] = inv[0] = fact[1] = inv[1] = 1;
    for (int i = 2; i <= mxA; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
        inv[i] = exp(fact[i], M - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    precomp();
    while (n--)
    {
        ull a, b;
        cin >> a >> b;
        cout << aCb(a, b) << '\n';
    }
}
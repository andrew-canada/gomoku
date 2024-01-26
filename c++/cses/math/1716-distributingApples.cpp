#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;

const int M = 1e9 + 7, mxA = 2e6;

ull f1[mxA + 1], f2[mxA + 1], inv[mxA + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    inv[1] = 1;
    for (int i = 2; i <= mxA; i++)
    {
        inv[i] = M - M / i * inv[M % i] % M;
    }
    f1[0] = f2[0] = 1;
    for (int i = 1; i <= mxA; i++)
    {
        f1[i] = i * f1[i - 1] % M;
        f2[i] = inv[i] * f2[i - 1] % M;
    }
    cout << ((f1[m + n - 1] * f2[n - 1]) % M * f2[m]) % M;
}
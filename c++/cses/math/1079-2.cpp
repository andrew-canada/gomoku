#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxA = 1e6;

ll inv[mxA + 1], f[mxA + 1], invF[mxA + 1];

int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
    }
    f[0] = inv[0] = 1;
    for (int i = 1; i <= mxA; i++)
    {
        f[i] = f[i - 1] * i;
    }
}
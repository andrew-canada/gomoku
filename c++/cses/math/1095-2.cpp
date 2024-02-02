#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, M = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    ll a, pow, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> pow;
        b = a;
        a = 1;
        while (pow)
        {
            if (pow & 1)
            {
                a = (a * b) % M;
            }
            b = (b * b) % M;
            pow >>= 1;
        }
        cout << a << '\n';
    }
}
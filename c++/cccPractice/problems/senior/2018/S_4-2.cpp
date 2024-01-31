#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

unordered_map<ll, ll> nt;

void getTrees(ll w)
{
    ll num = 0, nst = w, stw, nst1;
    while (nst > 1)
    {
        stw = w / nst;
        nst1 = w / (stw + 1);
        if (!nt[stw])
        {
            getTrees(stw);
        }
        num += nt[stw] * (nst - nst1);
        nst = nst1;
    }
    nt[w] = num;
}

int main()
{
    ll n;
    cin >> n;
    nt[1] = 1;
    if (n > 1)
    {
        getTrees(n);
    }
    cout << nt[n];
}
#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

vector<bool> ans(mxN + 1), start(mxN + 1);

int main()
{
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        start[i] = s[i] - '0';
    }
    int l, r;
    ll cg;
    for (int i = 0; i < 50; i++)
    {
        cg = 1ll << i;
        if (t & cg)
        {
            for (int i = 0; i < n; i++)
            {
                l = ((0ll + i - cg) % n + n) % n;
                r = (0ll + i + cg) % n;
                ans[i] = start[l] ^ start[r];
            }
            start = ans;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }
}
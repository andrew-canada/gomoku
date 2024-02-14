#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int mxN = 2e5;

int arr[mxN + 1];
ll da[mxN + 1];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int type, a, b, u, k;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> a >> b >> u, --a, --b;
            da[a] += u, da[b + 1] -= u;
        }
        else
        {
            cin >> k, --k;
            ll ans = arr[k];
            for (int i = 0; i <= k; i++)
            {
                ans += da[i];
            }
            cout << ans << '\n';
        }
    }
}
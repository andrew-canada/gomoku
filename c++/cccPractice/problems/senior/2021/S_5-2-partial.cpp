#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 15e4;

int ans[mxN + 1];
int a[mxN + 1], b[mxN + 1], c[mxN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        for (int j = a[i]; j <= b[i]; j++)
        {
            if (ans[j] == 0)
            {
                ans[j] = c[i];
            }
            else
            {
                ans[j] = lcm(ans[j], c[i]);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int val = 0;
        for (int j = a[i]; j <= b[i]; j++)
        {
            val = gcd(val, ans[j]);
        }
        if (val != c[i])
        {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != 0)
        {
            cout << ans[i] << " ";
        }
        else
        {
            cout << "1 ";
        }
    }
}
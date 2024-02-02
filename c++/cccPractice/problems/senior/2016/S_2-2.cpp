#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 100;

int a[mxN + 1], b[mxN + 1];

int main()
{
    // 1=min, 2=max
    int type, n;
    cin >> type >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    if (type == 1)
    {
        sort(a, a + n);
        sort(b, b + n);
    }
    else
    {
        sort(a, a + n);
        sort(b, b + n, greater<int>());
    }
    for (int i = 0; i < n; i++)
    {
        ans += max(a[i], b[i]);
    }
    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 100;

int v[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v + n);
    double ans = INF;
    for (int i = 1; i < n - 1; i++)
    {
        ans = min(ans, (1.0 + v[i + 1] + v[i]) / 2 - (1.0 + v[i] + v[i - 1]) / 2);
    }
    cout << fixed << setprecision(1) << ans;
}
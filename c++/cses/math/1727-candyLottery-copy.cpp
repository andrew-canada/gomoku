#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

const int mxN = 100;

double p[mxN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        p[i] = 1;
        for (int j = 0; j < n; j++)
        {
            p[i] *= (double)i / k;
        }
    }
    double ans = 0;
    for (int i = k; i > 0; i--)
    {
        p[i] -= p[i - 1];
        ans += i * p[i];
    }
    cout << fixed << setprecision(6) << ans;
}
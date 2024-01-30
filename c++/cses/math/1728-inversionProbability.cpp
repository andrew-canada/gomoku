#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

const int mxN = 100;

int r[mxN + 1];

int main()
{
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        for (int j = 0; j < i; j++)
        {
            int c = min(r[i], r[j]) * (min(r[i], r[j]) - 1) / 2;
            if (r[j] > r[i])
            {
                c += (r[j] - r[i]) * r[i];
            }
            ans += (double)c / (r[j] * r[i]);
        }
    }
    cout << fixed << setprecision(6) << ans;
}
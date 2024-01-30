#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

const int mxN = 100;

double prob[mxN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        prob[i] = 1;
        for (int j = 0; j < n; j++)
        {
            prob[i] *= (double)i / k;
        }
    }
    double ans = 0;
    for (int i = k; i > 0; i--)
    {
        prob[i] -= prob[i - 1];
        ans += i * prob[i];
    }
    cout << fixed << setprecision(6) << ans;
}
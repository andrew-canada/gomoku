#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int app[mxN + 1];
int apt[mxN + 1];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> app[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> apt[i];
    }
    sort(app, app + n), sort(apt, apt + m);
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && apt[j] < apt[i] - k)
        {
            j++;
        }
        if (j < m && apt[j] <= apt[i] + k)
        {
            j++, ans++;
        }
    }
    cout << ans;
}
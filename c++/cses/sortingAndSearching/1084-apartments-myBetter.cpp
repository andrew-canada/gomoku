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
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        if (abs(app[i] - apt[j]) <= k)
        {
            i++, j++, ans++;
        }
        else if (app[i] > apt[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << ans;
}
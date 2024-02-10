#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans[26][26];
bool cat[26][26];

int main()
{
    int r, c, k, cr, cc;
    cin >> r >> c >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> cr >> cc;
        cat[cr][cc] = true;
    }
    ans[1][1] = true;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (cat[i][j])
            {
                continue;
            }
            ans[i][j] += ans[i][j - 1] + ans[i - 1][j];
        }
    }
    cout << ans[r][c];
}
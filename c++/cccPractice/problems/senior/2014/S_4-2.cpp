#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 1e3, mxM = 2001000;

set<int> xc, yc;
array<int, 5> w[mxN + 5];
map<int, int> xp, yp;
int xv[2 * mxN + 5], yv[2 * mxN + 5], da[2 * mxN + 5][2 * mxN + 5];

int main()
{
    int n, t;
    cin >> n >> t;
    int lx, ly, rx, ry, ct;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> lx >> ly >> rx >> ry >> ct;
        w[i] = {lx, ly, rx, ry, ct};
        xc.insert(lx), xc.insert(rx);
        yc.insert(ly), yc.insert(ry);
    }
    int num = 1;
    for (int x : xc)
    {
        xp[x] = num, xv[num] = x;
        num++;
    }
    num = 1;
    for (int y : yc)
    {
        yp[y] = num, yv[num] = y;
        num++;
    }
    for (const array<int, 5> &cw : w)
    {
        da[xp[cw[0]]][yp[cw[1]]] += cw[4];
        da[xp[cw[2]]][yp[cw[3]]] += cw[4];
        da[xp[cw[0]]][yp[cw[3]]] -= cw[4];
        da[xp[cw[2]]][yp[cw[1]]] -= cw[4];
    }
    for (int i = 1; i < xc.size(); i++)
    {
        for (int j = 1; j < yc.size(); j++)
        {
            da[i][j] = da[i][j] + da[i][j - 1] + da[i - 1][j] - da[i - 1][j - 1];
            if (da[i][j] >= t)
            {
                // cout << xv[i + 1] << " " << xv[i] << '\n';
                // cout << yv[j + 1] << " " << yv[j] << '\n';
                ans += (0ll + xv[i + 1] - xv[i]) * (0ll + yv[j + 1] - yv[j]);
            }
        }
    }
    cout << ans;
}
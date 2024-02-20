#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 2e3;

set<int> x, y;
map<int, int> nx, ny;
int xv[mxN + 5], yv[mxN + 5], diff[mxN + 1][mxN + 1];
vector<array<int, 5>> arr;

int main()
{
    int n, t, tx, ty, bx, by, tf;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> tx >> ty >> bx >> by >> tf;
        arr.pb({tx, ty, bx, by, tf});
        x.insert(tx), x.insert(bx);
        y.insert(ty), y.insert(by);
    }
    int num = 1;
    for (int i : x)
    {
        nx[i] = num;
        xv[num] = i;
        num++;
    }
    num = 1;
    for (int i : y)
    {
        ny[i] = num;
        yv[num] = i;
        num++;
    }
    for (const array<int, 5> &a : arr)
    {
        diff[nx[a[0]]][ny[a[1]]] += a[4];
        diff[nx[a[2]]][ny[a[3]]] += a[4];
        diff[nx[a[0]]][ny[a[3]]] -= a[4];
        diff[nx[a[2]]][ny[a[1]]] -= a[4];
    }
    ll ans = 0;
    for (int i = 1; i <= x.size(); i++)
    {
        for (int j = 1; j <= y.size(); j++)
        {
            diff[i][j] = diff[i][j] + diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
            if (diff[i][j] >= t)
            {
                ans += 1ll * (xv[i + 1] - xv[i]) * (yv[j + 1] - yv[j]);
            }
        }
    }
    cout << ans;
}
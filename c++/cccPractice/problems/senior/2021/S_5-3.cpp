#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 150000, mxZ = 16;

int n, m;
array<int, 3> arr[mxN + 1];
int diff[mxN + 1][mxZ + 1], psa[mxZ + 1], ans[mxN + 1], st[4 * mxN];

void build(int ti = 1, int tl = 0, int tr = n)
{
    if (tl == tr)
    {
        st[ti] = ans[tl];
    }
    else
    {
        int mid = (tl + tr) / 2;
        build(ti * 2, tl, mid);
        build(ti * 2 + 1, mid + 1, tr);
        st[ti] = gcd(st[ti * 2], st[ti * 2 + 1]);
    }
}

int query(int l, int r, int ti = 1, int tl = 0, int tr = n)
{
    if (tl >= l && tr <= r)
    {
        return st[ti];
    }
    int mid = (tl + tr) / 2;
    return gcd(l <= mid ? query(l, r, ti * 2, tl, mid) : 0,
               r > mid ? query(l, r, ti * 2 + 1, mid + 1, tr) : 0);
}

int main()
{
    cin >> n >> m;
    fill(ans, ans + n + 1, 1);
    for (int i = 0, l, r, gcd; i < m; i++)
    {
        cin >> l >> r >> gcd;
        arr[i] = {l, r, gcd};
        diff[l][gcd]++;
        diff[r + 1][gcd]--;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 16; j++)
        {
            psa[j] += diff[i][j];
        }
        for (int j = 1; j <= 16; j++)
        {
            if (psa[j])
            {
                ans[i] = lcm(ans[i], j);
            }
        }
    }
    build();
    for (int i = 0; i < m; i++)
    {
        if (query(arr[i][0], arr[i][1]) != arr[i][2])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}
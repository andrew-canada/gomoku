#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int diam = 1e6;

int h, k;
vector<int> hl;
int vis[diam + 1];

bool valid(int len)
{
    memset(vis, 0, sizeof(vis));
    int rh = h, rk = k;
    for (int i = 0; i < h && rh && rk; i++)
    {
        if (vis[i])
        {
            continue;
        }
        // place this hydrant len away from house i to maxize houses reached
        rh--, rk--;
        for (int j = i + 1; j < h; j++)
        {
            // hose can wrap around because circular
            int reqL = min(hl[j] - hl[i], hl[i] + diam - hl[j]);
            if (reqL <= 2 * len && !vis[j])
            {
                rh--;
                vis[j] = true;
            }
        }
    }
    return rh == 0;
}

int main()
{
    cin >> h;
    for (int i = 0, ch; i < h; i++)
    {
        cin >> ch;
        hl.pb(ch);
    }
    cin >> k;
    if (k >= h)
    {
        cout << 0;
        return 0;
    }
    sort(hl.begin(), hl.end());
    int low = 0, high = diam, mid, ans;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (valid(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
}
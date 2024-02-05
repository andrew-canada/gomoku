#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main()
{
    int k, m;
    cin >> k >> m;
    int x;
    vector<int> ans, cur;
    for (int i = 1; i <= k; i++)
    {
        ans.pb(i);
    }
    while (m--)
    {
        cin >> x;
        for (int i = 0; i < ans.size(); i++)
        {
            if ((i + 1) % x)
            {
                cur.pb(ans[i]);
            }
        }
        ans = cur;
        cur.clear();
    }
    for (int i : ans)
    {
        cout << i << '\n';
    }
}
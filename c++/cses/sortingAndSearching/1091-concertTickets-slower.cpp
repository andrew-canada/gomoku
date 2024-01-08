#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

set<array<int, 2>> h;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int p;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        h.insert({p, i});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        auto it = h.lower_bound({p + 1, 0});
        if (it == h.begin())
        {
            cout << "-1\n";
        }
        else
        {
            --it;
            cout << (*it)[0] << '\n';
            h.erase(it);
        }
    }
}
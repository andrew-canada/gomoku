#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

map<int, int> mp;

int main()
{
    int n, x;
    cin >> n >> x;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (mp.find(x - a) != mp.end())
        {
            cout << i << " " << mp[x - a];
            return 0;
        }
        mp[a] = i;
    }
    cout << "IMPOSSIBLE\n";
}
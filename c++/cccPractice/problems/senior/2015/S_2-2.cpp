#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxA = 1e6;

map<int, char> mp;

int main()
{
    int j, a;
    cin >> j >> a;
    char sz;
    for (int i = 1; i <= j; i++)
    {
        cin >> sz;
        mp[i] = sz;
    }
    int n, ans = 0;
    for (int i = 0; i < a; i++)
    {
        cin >> sz >> n;
        if (mp[n] <= sz)
        {
            ans++;
            mp[n] = 'Z';
        }
    }
    cout << ans;
}
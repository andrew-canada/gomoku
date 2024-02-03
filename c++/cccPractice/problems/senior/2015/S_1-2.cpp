#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

int main()
{
    int k, x, ans = 0;
    cin >> k;
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        if (x)
        {
            v.pb(x);
        }
        else
        {
            v.pop_back();
        }
    }
    for (int i : v)
    {
        ans += i;
    }
    cout << ans;
}
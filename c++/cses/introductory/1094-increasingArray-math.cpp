#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int cur = 0, mx = 0;
    ll moves = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        mx = max(mx, cur);
        moves += mx - cur;
    }
    cout << moves;
}
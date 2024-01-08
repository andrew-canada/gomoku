#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = -1e18;

int main()
{
    int n;
    cin >> n;
    ll ms = INF, msf = INF;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        msf = max(0ll + x, msf + x);
        ms = max(ms, msf);
    }
    cout << ms;
}
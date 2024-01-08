#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int dp0[mxN + 1], dp1[mxN + 1];

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b, --a, --b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    dfs();
    cout << max(dp0[0], dp1[0]);
}
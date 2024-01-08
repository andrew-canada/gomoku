#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
bool used[mxN + 1];
int ans;

void dfs(int cur, int par)
{
    for (int i : adjL[cur])
    {
        if (i != par)
        {
            dfs(i, cur);
            if (!used[i] && !used[cur])
            {
                used[i] = true, used[cur] = true;
                ans++;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b, --a, --b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    dfs(0, -1);
    cout << ans;
}
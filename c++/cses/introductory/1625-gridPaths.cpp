#include <bits/stdc++.h>

using namespace std;

string s;
int ans;
bool vis[7][7];

bool isSafe(int r, int c)
{
    return r >= 0 && r < 8 && c >= 0 && c < 8 && !vis[r][c];
}

void dfs(int r, int c, int steps)
{
    if (r == 6 && c == 0)
    {
        if (steps == 48)
        {
            ans++;
        }
        return;
    }
    vis[r][c] = true;
    if (grid[r][c] == '?' || grid[r][c] == 'L')
    {
        if (j && !vis[r][c - 1])
        {
            if (!(!isSafe(r, c - 2) && isSafe(r - 1, c - 1) && isSafe(r + 1, c - 1)))
            {
                dfs(r, c - 1, steps + 1);
            }
        }
    }
    vis[r][c] = false;
}

int main()
{
    cin >> s;
    dfs(0, 0, 48);
    cout << ans;
}
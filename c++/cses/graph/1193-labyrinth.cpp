#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3;
const int rDir[4] = {1, 0, -1, 0}, cDir[4] = {0, 1, 0, -1};
const char dirChar[4] = {'D', 'R', 'U', 'L'};

int n, m, dirNum[mxN + 1][mxN + 1];
string s[mxN + 1], path[mxN + 1];

bool isSafe(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m && s[r][c] == '.';
}

int main()
{
    int sr, sc, er, ec;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'A')
            {
                sr = i, sc = j;
            }
            else if (s[i][j] == 'B')
            {
                er = i, ec = j;
                s[i][j] = '.';
            }
        }
        path[i] = string(m, 0);
    }

    queue<array<int, 2>> q;
    q.push({sr, sc});
    while (!q.empty())
    {
        array<int, 2> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = cur[0] + rDir[i], nc = cur[1] + cDir[i];
            if (!isSafe(nr, nc))
            {
                continue;
            }
            q.push({nr, nc});
            path[nr][nc] = dirChar[i];
            dirNum[nr][nc] = i;
            s[nr][nc] = '#';
        }
    }

    if (path[er][ec])
    {
        cout << "YES\n";
        string ans;
        while (sr ^ er || sc ^ ec)
        {
            ans += path[er][ec];
            int dir = dirNum[er][ec] ^ 2;
            er += rDir[dir], ec += cDir[dir];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans;
    }
    else
    {
        cout << "NO\n";
    }
}
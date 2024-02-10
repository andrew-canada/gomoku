#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 2e6, mxR = 1e3;

map<int, bool> vis;
bool occ[9];

int bfs(string &start, string &tar)
{
    // cur arrangement, num moves
    queue<pair<string, int>> q;
    pair<string, int> cur;
    vis.clear();
    vis[stoi(start)] = true;
    q.push({start, 0});
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.first == tar)
        {
            return cur.second;
        }
        memset(occ, false, sizeof(occ));
        for (int i = 0; i < cur.first.size(); i++)
        {
            int pos = cur.first[i] - '0';
            if (occ[pos])
            {
                continue;
            }
            occ[pos] = true;
            if (pos > 0)
            {
                auto left = cur.first.find(to_string(pos - 1));
                if (left > i || left == string::npos)
                {
                    string nxt = cur.first;
                    nxt[i] = pos - 1 + '0';
                    if (!vis[stoi(nxt)])
                    {
                        q.push({nxt, cur.second + 1});
                        vis[stoi(nxt)] = true;
                    }
                }
            }
            if (pos < cur.first.size() - 1)
            {
                auto right = cur.first.find(to_string(pos + 1));
                if (right > i || right == string::npos)
                {
                    string nxt = cur.first;
                    nxt[i] = pos + 1 + '0';
                    if (!vis[stoi(nxt)])
                    {
                        q.push({nxt, cur.second + 1});
                        vis[stoi(nxt)] = true;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cin >> n;
    while (n)
    {
        string start(n, ' '), tar;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            start[x - 1] = i + '0';
            tar += (i + '0');
        }
        cin >> n;
        int ans = bfs(start, tar);
        if (ans == -1)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cout << ans << '\n';
        }
    }
}
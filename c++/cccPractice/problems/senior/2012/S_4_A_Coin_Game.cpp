// n types of coin, value of coin x is x
// smaller value can be stacked on larger value
// only adjacent movement
// goal: arrange coins in increasing order
// use bfs

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
unordered_map<int, bool> vis;
unordered_map<int, int> mv;

int bfs(string s, string ord);

int main()
{
    int num;
    while (1)
    {
        scanf("%d", &n);
        if (!n)
        {
            break;
        }
        string ord = "";
        string s(n, 'a');
        REP(i, 0, n)
        {
            scanf("%d", &num);
            s[num - 1] = i + 1 + '0';
            ord += to_string(i + 1);
        }
        int m = bfs(s, ord);
        m == -1 ? printf("IMPOSSIBLE\n") : printf("%d\n", m);
    }
}

int bfs(string s, string ord)
{
    queue<string> q;
    vis.clear();
    mv.clear();
    mv[stoi(s)] = 0;
    vis[stoi(s)] = 1;
    q.push(s);
    string cur;
    bool stackVis[10];
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == ord)
        {
            return mv[stoi(cur)];
        }
        memset(stackVis, 0, sizeof(stackVis));
        REP(i, 0, cur.length())
        {
            int pos = cur[i] - '0';
            if (stackVis[pos])
            {
                continue;
            }
            stackVis[pos] = 1;
            if (pos > 1)
            {
                auto Lpos = cur.find(to_string(pos - 1));
                if (Lpos == string::npos || Lpos > i)
                {
                    string nxt = cur;
                    nxt[i] = pos - 1 + '0';
                    if (!vis[stoi(nxt)])
                    {
                        q.push(nxt);
                        mv[stoi(nxt)] = mv[stoi(cur)] + 1;
                        vis[stoi(nxt)] = 1;
                    }
                }
            }
            if (pos < cur.length())
            {
                auto Rpos = cur.find(to_string(pos + 1));
                if (Rpos == string::npos || Rpos > i)
                {
                    string nxt = cur;
                    nxt[i] = pos + 1 + '0';
                    if (!vis[stoi(nxt)])
                    {
                        q.push(nxt);
                        mv[stoi(nxt)] = mv[stoi(cur)] + 1;
                        vis[stoi(nxt)] = 1;
                    }
                }
            }
        }
    }
    return -1;
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e4;

int ans, nga;
int tree[mxN + 1];
// production of node i if given j ga, production of children
int dp[mxN + 1][2501], child[mxN + 1][2501];

void dfs(int ti)
{
    // root or leaf
    if (tree[ti])
    {
        for (int tot = 0; tot <= nga; tot++)
        {
            for (int node = 0; node <= tot; node++)
            {
                int edge = tot - node;
                // limited by edge
                dp[ti][tot] = max(dp[ti][tot], min(tree[ti] + node, (edge + 1) * (edge + 1)));
            }
        }
    }
    // inner -> do dfs
    else
    {
        dfs(ti * 2), dfs(ti * 2 + 1);
        // node distribution
        for (int tot = 0; tot <= nga; tot++)
        {
            for (int l = 0; l <= tot; l++)
            {
                int r = tot - l;
                child[ti][tot] = max(child[ti][tot], dp[2 * ti][l] + dp[2 * ti + 1][r]);
                if (ti == 1)
                {
                    ans = max(ans, child[ti][tot]);
                }
            }
        }
        // edge
        for (int tot = 0; tot <= nga; tot++)
        {
            for (int node = 0; node <= tot; node++)
            {
                int edge = tot - node;
                dp[ti][tot] = max(dp[ti][tot], min(child[ti][node], (edge + 1) * (edge + 1)));
            }
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    cin >> nga;
    if (s[0] != '(')
    {
        cout << stoi(s) + nga;
        return 0;
    }
    int ai = 1, ti = 1, l, r;
    stack<string> stk;
    stk.push("(");
    while (stk.size())
    {
        if (s[ai] == ' ')
        {
            ai++;
            continue;
        }
        else if (s[ai] == '(')
        {
            // left child
            if (stk.top() == "(")
            {
                ti *= 2;
            }
            // right child
            else
            {
                ti = ti * 2 + 1;
            }
            stk.push("(");
            ai++;
        }
        else if (s[ai] == ')')
        {
            r = stoi(stk.top());
            stk.pop();
            l = stoi(stk.top());
            stk.pop();
            // opening parenthase
            stk.pop();
            tree[ti * 2] = l, tree[ti * 2 + 1] = r;
            ti /= 2;
            ai++;
            // must fill if inner node (not leaf)
            if (stk.size())
            {
                stk.push("0");
            }
        }
        else
        {
            string num = "";
            while (s[ai] != ' ' && s[ai] != '(' && s[ai] != ')')
            {
                num += s[ai];
                ai++;
            }
            stk.push(num);
        }
    }
    dfs(1);
    cout << ans;
}

/*
(5 ((7 1) (3 4)))
3

out:
7
*/
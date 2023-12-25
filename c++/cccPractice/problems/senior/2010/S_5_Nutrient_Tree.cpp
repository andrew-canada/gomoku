/*
binary tree with l leaves [1, 51]
each leaf k produces nk nutrients [1, 10'000]
each edge has weight 1
x growth agents [1, 2500]
give edge w agents = new weight of (1+w)^2
give leaf w agents = new production of nk+w
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

string leaves;
int ga;
int tree[10005];
int cp[10005][2505];
int dp[10005][2505];
int mp;

void dfs(int n);

int main()
{
    getline(cin, leaves);
    scanf("%d", &ga);
    if (leaves[0] != '(')
    {
        printf("%d", ga + stoi(leaves));
        return 0;
    }
    stack<string> s;
    int i = 1;
    int n = 1;
    int l, r;
    s.push("(");
    while (!s.empty())
    {
        if (leaves[i] == ' ')
        {
            i++;
            continue;
        }
        if (leaves[i] == '(')
        {
            if (s.top() == "(")
            {
                n *= 2;
            }
            else
            {
                n = n * 2 + 1;
            }
            s.push("(");
            i++;
        }
        else if (leaves[i] == ')')
        {
            r = stoi(s.top());
            s.pop();
            l = stoi(s.top());
            s.pop();
            s.pop();
            tree[n * 2] = l, tree[n * 2 + 1] = r;
            i++;
            n /= 2;
            if (!s.empty())
            {
                s.push("0");
            }
        }
        else
        {
            string prod = "";
            while (leaves[i] != '(' && leaves[i] != ')' && leaves[i] != ' ')
            {
                prod += leaves[i];
                i++;
            }
            s.push(prod);
        }
    }
    dfs(1);
    printf("%d", mp);
}

void dfs(int n)
{
    int eg;
    int r;
    if (tree[n])
    {
        REP(tg, 0, ga)
        {
            REP(ng, 0, tg)
            {
                eg = tg - ng;
                dp[n][tg] = max(dp[n][tg], min(ng + tree[n], (1 + eg) * (1 + eg)));
            }
        }
    }
    else
    {
        dfs(n * 2), dfs(n * 2 + 1);
        REP(tg, 0, ga)
        {
            REP(l, 0, tg)
            {
                r = tg - l;
                cp[n][tg] = max(cp[n][tg], dp[n * 2][l] + dp[n * 2 + 1][r]);
                if (n == 1)
                {
                    mp = max(mp, cp[n][tg]);
                }
            }
        }
        REP(tg, 0, ga)
        {
            REP(ng, 0, tg)
            {
                eg = tg - ng;
                dp[n][tg] = max(dp[n][tg], min(cp[n][ng], (1 + eg) * (1 + eg)));
            }
        }
    }
}
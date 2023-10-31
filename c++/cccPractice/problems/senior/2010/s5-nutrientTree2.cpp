#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int x;
string ts;
stack<string> s;
int tree[10000];
int maxNutrient;
int dp[10005][2505];
int children[10000][2505];

void dfs(int n);

int main()
{
    getline(cin, ts);
    scanf("%d", &x);
    if (ts[0] != '(')
    {
        printf("%d", stoi(ts) + x);
        return 0;
    }
    char c;
    int i = 1;
    int n = 1;
    int l, r;
    s.push("(");
    while (!s.empty())
    {
        if (ts[i] == ' ')
        {
            i++;
            continue;
        }
        if (ts[i] == '(')
        {
            if (s.top() == "(")
            {
                n *= 2;
            }
            else
            {
                n = n * 2 + 1;
            }
            i++;
            s.push("(");
        }
        else if (ts[i] == ')')
        {
            r = stoi(s.top());
            s.pop();
            l = stoi(s.top());
            s.pop();
            s.pop();
            tree[n * 2] = l;
            tree[n * 2 + 1] = r;
            if (!s.empty())
            {
                s.push("0");
            }
            i++;
            n /= 2;
        }
        else
        {
            string num = "";
            while (true)
            {
                num += ts[i];
                i++;
                if (ts[i] == '(' || ts[i] == ')' || ts[i] == ' ')
                {
                    s.push(num);
                    break;
                }
            }
        }
    }
    dfs(1);
    printf("%d", maxNutrient);
}

void dfs(int n)
{
    if (tree[n])
    {
        REP(tot, 0, x)
        {
            REP(edge, 0, tot)
            {
                int node = tot - edge;
                dp[n][tot] = max(dp[n][tot], min(tree[n] + node, (1 + edge) * (1 + edge)));
            }
        }
    }
    else
    {
        dfs(n * 2);
        dfs(n * 2 + 1);
        REP(tot, 0, x)
        {
            REP(l, 0, tot)
            {
                int r = tot - l;
                children[n][tot] = max(children[n][tot], dp[n * 2][l] + dp[n * 2 + 1][r]);
                if (n == 1)
                {
                    maxNutrient = max(maxNutrient, children[n][tot]);
                }
            }
        }
        REP(tot, 0, x)
        {
            REP(e, 0, tot)
            {
                int node = tot - e;
                dp[n][tot] = max(dp[n][tot], min(children[n][node], (1 + e) * (1 + e)));
            }
        }
    }
}
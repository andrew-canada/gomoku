/*
n nodes, n>=2, numbered from [1, n]
each node is yes or no
all nodes are directy or indirectly connected
each node has cost to make adjacent nodes yes
connected nodes are given in n-1 lines of pairs
string of length n, yes or no
n integers, each cost
find min cost to make all nodes yes
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
vector<ll> adjL[200005];
char ynStr[200005];
bool part[200005];
ll cost[200005];
ll dp[200005][3];

void dfs(ll cur, ll par);

int main()
{
    ll n;
    scanf("%lld", &n);
    ll a, b;
    REP(i, 1, n - 1)
    {
        scanf("%lld%lld", &a, &b);
        adjL[a].pb(b);
        adjL[b].pb(a);
    }
    scanf("%s", ynStr);
    REP(i, 1, n)
    {
        part[i] = (ynStr[i - 1] == 'Y');
    }
    REP(i, 1, n)
    {
        scanf("%lld", &cost[i]);
    }
    dfs(1, -1);
    printf("%lld", dp[1][1]);
}

void dfs(ll cur, ll par)
{
    for (ll an : adjL[cur])
    {
        if (an != par)
        {
            dfs(an, cur);
        }
    }
    if (part[cur])
    {
        dp[cur][0] = INF, dp[cur][1] = 0, dp[cur][2] = cost[cur];
        for (ll an : adjL[cur])
        {
            if (an != par)
            {
                dp[cur][1] += dp[an][1];
                dp[cur][2] += dp[an][0];
            }
        }
    }
    else
    {
        ll inSum = 0, partSum = 0;
        for (ll an : adjL[cur])
        {
            if (an != par)
            {
                inSum += dp[an][0];
                partSum += dp[an][1];
            }
        }
        dp[cur][0] = min(partSum, inSum + cost[cur]), dp[cur][1] = INF, dp[cur][2] = INF;
        for (ll an : adjL[cur])
        {
            if (an != par)
            {
                dp[cur][1] = min(dp[cur][1], partSum - dp[an][1] + dp[an][2]);
                dp[cur][2] = min(dp[cur][2], inSum + cost[cur] - dp[an][0] + dp[an][2]);
            }
        }
    }
    dp[cur][1] = min(dp[cur][1], dp[cur][2]);
    dp[cur][0] = min(dp[cur][0], dp[cur][1]);
}
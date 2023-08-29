#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
const int INF = 0x3f3f3f3f;

const int MN = 2e5 + 5;
int n;
bool bArr[MN];
int cost[MN];
ll dp[MN][3];
vi adjList[MN];

void dfs(int n1, int par)
{
    for (int n2 : adjList[n1])
        if (n2 != par)
            dfs(n2, n1);

    if (bArr[n1])
    {
        dp[n1][0] = INF;
        dp[n1][1] = 0;
        dp[n1][2] = cost[n1];
        for (int n2 : adjList[n1])
        {
            if (n2 == par)
                continue;
            dp[n1][1] += dp[n2][1];
            dp[n1][2] += dp[n2][0];
        }
    }
    else
    {
        ll offSum = 0;
        ll oneSum = 0;
        for (int n2 : adjList[n1])
        {
            if (n2 == par)
                continue;
            offSum += dp[n2][0];
            oneSum += dp[n2][1];
        }
        dp[n1][0] = min(offSum + cost[n1], oneSum);
        dp[n1][1] = INF;
        dp[n1][2] = INF;
        for (int n2 : adjList[n1])
        {
            if (n2 == par)
                continue;
            dp[n1][2] = min(dp[n1][2], offSum - dp[n2][0] + dp[n2][2] + cost[n1]);
            dp[n1][1] = min(dp[n1][1], oneSum - dp[n2][1] + dp[n2][2]);
        }
    }

    dp[n1][1] = min(dp[n1][1], dp[n1][2]);
    dp[n1][0] = min(dp[n1][0], dp[n1][1]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
        bArr[i] = str[i] == 'Y';
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    dfs(0, -1);
    cout << dp[0][1] << '\n';
}
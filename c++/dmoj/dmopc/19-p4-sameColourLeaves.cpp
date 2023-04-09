#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back

int n;
vector<int> adj[300005];
char col[300005];
int v1, v2;

pair<int, int> dfs(int n1, int par)
{
}

int main()
{
    scanf("%d", &n);
    scanf("%s", &col);
    REP(i, 0, n - 1)
    {
        scanf("%d %d", &v1, &v2);
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
}
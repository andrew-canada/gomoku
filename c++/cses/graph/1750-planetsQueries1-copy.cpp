#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7;

int tar[mxN + 1][30];

int main()
{
    int n, q, x, k;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tar[i][0]);
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            tar[i][j] = tar[tar[i][j - 1]][j - 1];
        }
    }
    while (q--)
    {
        scanf("%d%d", &x, &k);
        for (int i = 0; i < 30; i++)
        {
            if ((k >> i) & 1)
            {
                x = tar[x][i];
            }
        }
        cout << x << '\n';
    }
}
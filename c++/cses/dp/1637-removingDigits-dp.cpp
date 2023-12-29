#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f

const int mxN = 1e6;
int dp[mxN + 1];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 1, n)
    {
        dp[i] = INF;
        int n1 = i;
        while (n1)
        {
            dp[i] = min(dp[i], dp[i - n1 % 10] + 1);
            n1 /= 10;
        }
    }
    printf("%d\n", dp[n]);
}
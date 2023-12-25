#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define pb push_back

int dp[100][2][100];
vector<int> n;

int np(int pos, bool ad, int nd);
int getNum(int num);

int l = 14, r = 44, d = 4, k = 1;

int main()
{
    printf("%d\n", getNum(r) - getNum(l - 1));
}

int np(int pos, bool ad, int nd)
{
    if (pos == n.size())
    {
        return nd == k;
    }
    if (dp[pos][ad][nd] != -1)
    {
        return dp[pos][ad][nd];
    }
    int num = 0;
    if (ad)
    {
        REP(i, 0, 9)
        {
            num += np(pos + 1, 1, nd + (i == d));
        }
    }
    else
    {
        REP(i, 0, n[pos])
        {
            if (i < n[pos])
            {
                num += np(pos + 1, 1, nd + (i == d));
            }
            else
            {
                num += np(pos + 1, 0, nd + (i == d));
            }
        }
    }
    dp[pos][ad][nd] = num;
    return num;
}

int getNum(int num)
{
    n.clear();
    memset(dp, -1, sizeof(dp));
    while (num > 0)
    {
        n.pb(num % 10);
        num /= 10;
    }
    reverse(n.begin(), n.end());
    return np(0, 0, 0);
}
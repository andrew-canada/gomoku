#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define pb push_back

int dp[100][2][100][100];
vector<int> n;

int np(int pos, bool ad, int f, int l);
int getNum(int num);

int l = 14, r = 44;

int main()
{
    printf("%d\n", getNum(r) - getNum(l - 1));
}

int np(int pos, bool ad, int f, int l)
{
    if (pos == n.size())
    {
        return f == l;
    }
    if (dp[pos][ad][f][l] != -1)
    {
        return dp[pos][ad][f][l];
    }
    int num = 0;
    int nf, nl;
    if (ad)
    {
        REP(i, 0, 9)
        {
            nf = f, nl = i;
            if (nf == 0)
            {
                nf = i;
            }
            num += np(pos + 1, 1, nf, nl);
        }
    }
    else
    {
        REP(i, 0, n[pos])
        {
            nf = f, nl = i;
            if (nf == 0)
            {
                nf = i;
            }
            if (i < n[pos])
            {
                num += np(pos + 1, 1, nf, nl);
            }
            else
            {
                num += np(pos + 1, 0, nf, nl);
            }
        }
    }
    dp[pos][ad][f][l] = num;
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
    return np(0, 0, 0, 0);
}
/*
m row, n col

BGBBB
BGBBB
GBGGG
GBGGG

*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

bool r[5000005];
bool c[5000005];

int main()
{
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    char rc;
    int num;
    REP(i, 0, k - 1)
    {
        scanf(" %c%d", &rc, &num);
        if (rc == 'R')
        {
            r[num] = !r[num];
        }
        else
        {
            c[num] = !c[num];
        }
    }
    int gr = 0, gc = 0;
    REP(i, 1, m)
    {
        if (r[i])
        {
            gr++;
        }
    }
    REP(i, 1, n)
    {
        if (c[i])
        {
            gc++;
        }
    }
    printf("%d", gr * n + gc * m - 2 * gr * gc);
}
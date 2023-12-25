/*
create music of length n note, each note [1, m]
music must have k different contiguous sequence with all different notes
different = start and/or end at different position
output the music; output -1 if impossible
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int music[1000005];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int sr = k - n;
    if (sr < 0)
    {
        printf("-1");
    }
    int i = 1;
    for (i; i <= m; i++)
    {
        music[i - 1] = i;
        sr = sr - i + 1;
        if (sr == 0)
        {
            break;
        }
    }
    if (sr == 0)
    {
        REP(j, i, n - 1)
        {
            music[j] = i;
        }
    }
    else
    {
        REP(j, m - nr, m)
        {
            music[i] = j;
            i++;
        }
    }
    if (sr == 0)
    {
        REP(j, 0, n - 1)
        {
            printf("%d ", music[j]);
        }
    }
    else
    {
        printf("-1");
    }
}
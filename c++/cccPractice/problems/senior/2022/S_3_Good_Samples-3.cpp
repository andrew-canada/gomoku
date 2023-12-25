/*
create music of length n note, each note [1, m]
music must have k different contiguous sequence with all different notes
different = start and/or end at different position
output the music; output -1 if impossible
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

int music[1000005];

int main()
{
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    ll sr = k - n;
    if (sr < 0)
    {
        printf("-1");
        return 0;
    }
    int val = 1;
    for (val; val <= m && val <= n; val++)
    {
        if (sr - val + 1 >= 0)
        {
            music[val - 1] = val;
            sr = sr - val + 1;
        }
        else
        {
            break;
        }
    }
    REP(i, val - 1, n - 1)
    {
        if (sr)
        {
            for (int j = m; j > 1; j--)
            {
                if (sr - j + 1 >= 0)
                {
                    music[i] = music[i - j];
                    sr = sr - j + 1;
                    break;
                }
            }
        }
        else
        {
            music[i] = music[i - 1];
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
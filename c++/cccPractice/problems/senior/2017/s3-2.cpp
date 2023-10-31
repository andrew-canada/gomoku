#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
int wood[2005];
int fl, nf;
int cfl;

int main()
{
    scanf("%d", &n);
    int w;
    REP(i, 1, n)
    {
        scanf("%d", &w);
        wood[w]++;
    }
    int w2;
    REP(h, 2, 4000)
    {
        cfl = 0;
        REP(w1, 1, h / 2)
        {
            w2 = h - w1;
            if (w2 <= 2000)
            {
                if (w1 == w2)
                {
                    cfl += wood[w1] / 2;
                }
                else
                {
                    cfl += min(wood[w1], wood[w2]);
                }
            }
        }
        if (cfl > fl)
        {
            fl = cfl;
            nf = 1;
        }
        else if (cfl == fl)
        {
            nf++;
        }
    }
    printf("%d %d", fl, nf);
}
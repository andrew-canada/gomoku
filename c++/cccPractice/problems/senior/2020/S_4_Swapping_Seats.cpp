#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f

char seat[1000005];
int psa[3][1000005];
int ms = INF;
int group[3] = {0, 1, 2};

int np(int g, int begin, int ppl);
void ns(int a, int b, int c, int n);

int main()
{
    scanf("%s", seat);
    int n = strlen(seat);
    REP(i, 0, 2)
    {
        REP(j, 1, n)
        {
            psa[i][j] = psa[i][j - 1] + (seat[j - 1] - 'A' == i);
        }
    }
    do
    {
        ns(group[0], group[1], group[2], n);
    } while (next_permutation(group, group + 3));
    printf("%d", ms);
}

int np(int g, int begin, int ppl)
{
    return psa[g][begin + ppl] - psa[g][begin];
}

void ns(int a, int b, int c, int n)
{
    int ta = psa[a][n];
    int tb = psa[b][n];

    int na, nb, nc;
    int aia, bib, cia, cib;
    int sa, sb;
    REP(i, 0, n - ta - tb)
    {
        na = np(a, i, ta + tb);
        nb = np(b, i, ta + tb);
        nc = np(c, i, ta + tb);

        aia = np(a, i, ta);
        bib = np(b, i, tb);
        cia = np(c, i, ta);
        cib = np(c, i, tb);

        sa = ta - na;
        sb = tb - nb;

        ms = min(ms, nc + min(ta - aia - min(sa, cia), tb - bib - min(sb, cib)));
    }
}
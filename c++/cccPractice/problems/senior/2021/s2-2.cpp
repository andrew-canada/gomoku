#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int r, c, b;
bool rows[5000005];
bool cols[5000005];
char rc;
int v;
int gr, gc;

int main()
{
    scanf("%d%d%d", &r, &c, &b);
    REP(i, 0, b - 1)
    {
        scanf(" %c%d", &rc, &v);
        if (rc == 'R')
        {
            rows[v] = !rows[v];
        }
        else
        {
            cols[v] = !cols[v];
        }
    }
    REP(i, 1, r)
    {
        if (rows[i])
        {
            gr++;
        }
    }
    REP(i, 1, c)
    {
        if (cols[i])
        {
            gc++;
        }
    }
    printf("%d", gr * c + gc * r - 2 * gr * gc);
}
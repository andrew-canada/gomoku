#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int r, c;
int n;
bool rows[5000005];
bool cols[5000005];
char rc;
int num;
int gr;
int gc;

int main()
{
    scanf("%d%d%d", &r, &c, &n);
    while (n--)
    {
        scanf(" %c %d", &rc, &num);
        if (rc == 'R')
        {
            rows[num] = !rows[num];
        }
        else
        {
            cols[num] = !cols[num];
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
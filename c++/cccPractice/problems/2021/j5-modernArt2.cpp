#include <stdio.h>

bool rows[5000000];
bool cols[5000000];
int r, c, b;
char rOrC;
int n;
int gr, gc;

int main()
{
    scanf("%d%d%d", &r, &c, &b);
    for (int i = 0; i < b; i++)
    {
        scanf(" %c %d", &rOrC, &n);
        if (rOrC == 'R')
        {
            rows[n] = !rows[n];
        }
        else
        {
            cols[n] = !cols[n];
        }
    }
    for (int i = 0; i <= r; i++)
    {
        if (rows[i])
        {
            gr += 1;
        }
    }
    for (int i = 0; i <= c; i++)
    {
        if (cols[i])
        {
            gc += 1;
        }
    }
    printf("%d", gr * c + gc * r - 2 * gr * gc);
}
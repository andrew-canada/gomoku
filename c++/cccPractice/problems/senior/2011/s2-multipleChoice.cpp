#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int n;
char sa[10005];
char ak;
int nc;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf(" %c", &sa[i]);
    }
    REP(i, 0, n)
    {
        scanf(" %c", &ak);
        if (ak == sa[i])
        {
            nc++;
        }
    }
    printf("%d", nc);
}
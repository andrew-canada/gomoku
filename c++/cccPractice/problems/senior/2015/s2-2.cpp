#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int j, a;
char jersey[1000005];
char sz;
int n;
int num;

int main()
{
    scanf("%d%d", &j, &a);
    REP(i, 1, j)
    {
        scanf(" %c", &jersey[i]);
    }
    REP(i, 1, a)
    {
        scanf(" %c %d", &sz, &n);
        if (jersey[n] <= sz)
        {
            num++;
            jersey[n] = 'Z';
        }
    }
    printf("%d", num);
}
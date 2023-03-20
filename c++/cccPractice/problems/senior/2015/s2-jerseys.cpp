#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int j, p;
int num;
int ns;
char sz;
char jerseys[1000005];

int main()
{
    scanf("%d%d", &j, &p);
    REP(i, 1, j)
    {
        scanf(" %c", &jerseys[i]);
    }
    REP(i, 1, p)
    {
        scanf(" %c %d", &sz, &num);
        if (jerseys[num] <= sz)
        {
            ns++;
            jerseys[num] = 'Z';
        }
    }
    printf("%d", ns);
}
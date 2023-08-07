#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
char seats[1000005];

int main()
{
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf(" %c", &seats[i]);
    }
}
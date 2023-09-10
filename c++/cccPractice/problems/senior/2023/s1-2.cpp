#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
bool t1[200005];
bool t2[200005];
int tl;

int main()
{
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &t1[i]);
        if (t1[i])
        {
            tl += 3;
        }
    }
    REP(i, 1, n)
    {
        scanf("%d", &t2[i]);
        if (t2[i])
        {
            tl += 3;
        }
    }
    REP(i, 1, n)
    {
        if (t1[i] && t1[i + 1])
        {
            tl -= 2;
        }
        if (t2[i] && t2[i + 1])
        {
            tl -= 2;
        }
        if ((i % 2 == 1) && t1[i] && t2[i])
        {
            tl -= 2;
        }
    }
    printf("%d", tl);
}
#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
int t1[100005], t2[100005];
int nd;

int main()
{
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &t1[i]);
        t1[i] += t1[i - 1];
    }
    REP(i, 1, n)
    {
        scanf("%d", &t2[i]);
        t2[i] += t2[i - 1];
    }
    REP(i, 1, n)
    {
        if (t1[i] == t2[i])
        {
            nd = i;
        }
    }
    printf("%d", nd);
}
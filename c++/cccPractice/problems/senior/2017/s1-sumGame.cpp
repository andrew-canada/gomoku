#include <stdio.h>

int sw[100001];
int se[100001];
int n;

int t1;
int t2;
int maxTie;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sw[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &se[i]);
    }

    for (int i = 0; i < n; i++)
    {
        t1 += sw[i];
        t2 += se[i];
        if (t1 == t2)
        {
            maxTie = i + 1;
        }
    }

    printf("%d", maxTie);
}
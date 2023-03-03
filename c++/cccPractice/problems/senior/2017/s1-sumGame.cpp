#include <stdio.h>

int sw[100001];
int n;

int t1;
int t2;
int maxTie;

int val;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sw[i]);
    }

    for (int i = 0; i < n; i++)
    {
        t1 += sw[i];
        scanf("%d", &val);
        t2 += val;
        if (t1 == t2)
        {
            maxTie = i + 1;
        }
    }

    printf("%d", maxTie);
}
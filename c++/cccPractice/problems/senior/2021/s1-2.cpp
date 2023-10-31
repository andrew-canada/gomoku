#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
int base[10005];
int h;
double area;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &base[i]);
    }
    REP(i, 0, n - 1)
    {
        scanf("%d", &h);
        area += (double)(base[i] + base[i + 1]) * h / 2;
    }
    printf("%.1f", area);
}
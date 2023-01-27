#include <stdio.h>

int main()
{
    int r, s;
    scanf("%d", &r);
    scanf("%d", &s);
    int total = r * 8 + s * 3;
    printf("%d\n", total > 28 ? total - 28 : 0);
}
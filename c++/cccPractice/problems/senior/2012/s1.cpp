#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    printf("%d", ((n - 1) * (n - 2) * (n - 3) / 6));
}
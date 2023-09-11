#include <stdio.h>

int n1, n2;
long long sum;

int main()
{
    n1 = 1000000000;
    n2 = 5000;
    sum = (long long)n1 * n2;
    printf("%d, %d, %lld", n1, n2, sum);
}
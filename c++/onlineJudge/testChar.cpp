#include <stdio.h>

int n[1];

int main()
{
    char c = 'é';
    n[c] = 1;
    printf("%d", n[c]);
}
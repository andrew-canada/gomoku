#include <stdio.h>

int main()
{
    int length = 1;
    int n1, n2, temp;
    scanf("%d%d", &n1, &n2);

    do
    {
        temp = n1;
        n1 = n2;
        n2 = temp - n2;
        length += 1;
    } while (n2 >= 0);

    printf("%d", length);
}
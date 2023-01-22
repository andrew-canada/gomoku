#include <stdio.h>
#include <algorithm>

int main()
{
    int n1, n2, f;
    int n2d[5];
    while (scanf("%d", &f) != 0)
    {
        n2 = 01234;

        n1 = 0;
        while (n1 <= 98765)
        {
            n2d[4] = n2 % 10;
            n2d[3] = n2 / 10 % 10;
            n2d[2] = n2 / 10 / 10 % 10;
            n2d[1] = n2 / 10 / 10 / 10 % 10;
            n2d[0] = n2 / 10 / 10 / 10 / 10;

            n1 = n2 * f;
            if (n1 > 98765)
            {
                printf("There are no solutions for %d.", f);
                break;
            }
            else if (std::find(n2d, n2d + 5, n1 % 10) == n2d + 5 &&
                     std::find(n2d, n2d + 5, n1 / 10 % 10) == n2d + 5 &&
                     std::find(n2d, n2d + 5, n1 / 10 / 10 % 10) == n2d + 5 &&
                     std::find(n2d, n2d + 5, n1 / 10 / 10 / 10 % 10) == n2d + 5 &&
                     std::find(n2d, n2d + 5, n1 / 10 / 10 / 10 / 10) == n2d + 5)
            {
                printf("%d / %d = %d", n1, n2, f);
            }
            n2 += 1;
        }
    }
}
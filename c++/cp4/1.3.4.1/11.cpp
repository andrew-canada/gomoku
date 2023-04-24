#include <stdio.h>

int n = 123;

int main()
{
    if (n <= 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                puts("Composite");
                return 0;
            }
        }
        puts("Prime");
    }
}